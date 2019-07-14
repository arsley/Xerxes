#include "rsocket.hpp"
#include "stdafx.hpp"

#include <arpa/inet.h>
#include <unistd.h>

Rsocket::Rsocket(std::string host, std::string port, int proto)
    : rhost{std::move(host)}, rport{std::move(port)}, proto{proto} {}

bool Rsocket::open() {
  int on = 1;
  if ((fd = socket(AF_INET, SOCK_RAW, proto)) == -1) {
    spdlog::get("logger")->error("socket error");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
    spdlog::get("logger")->error("setsockopt error: {0}", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (setsockopt(fd, SOL_SOCKET, SO_BROADCAST,
                 reinterpret_cast<const char *>(&on), sizeof(on)) == -1) {
    spdlog::get("logger")->error("setsockopt error: {0}", strerror(errno));
    exit(EXIT_FAILURE);
  }

  hostent *hp{gethostbyname(rhost.c_str())};
  if (hp == nullptr) {
    dst.sin_addr.s_addr = inet_addr(rhost.c_str());
    if (dst.sin_addr.s_addr == INADDR_NONE) {
      spdlog::get("logger")->error("can't resolve the host");
      exit(EXIT_FAILURE);
    }
  } else {
    bcopy(hp->h_addr_list[0], &dst.sin_addr.s_addr,
          static_cast<size_t>(hp->h_length));
  }

  dst.sin_family = AF_UNSPEC;
  bzero(dst.sin_zero, sizeof(dst.sin_zero));
  spdlog::get("logger")->info("Connected -> {0}:{1}", rhost, rport);
  return (fd > 0);
}

bool Rsocket::close() { return static_cast<bool>(::close(fd)); }

bool Rsocket::Open() { return open(); }

bool Rsocket::Close() { return close(); }

bool Rsocket::Alive() { return (fd > 0); }

ssize_t Rsocket::Write(const char *str, size_t len) {
  return static_cast<int>(sendto(fd, str, len, 0,
                                 reinterpret_cast<sockaddr *>(&dst),
                                 sizeof(struct sockaddr_in)));
}

sockaddr_in *Rsocket::GetDst() { return &dst; }
