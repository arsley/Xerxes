#include "null_tcp.hpp"

null_tcp::null_tcp() : tcp_flood() {}

int null_tcp::gen_hdr(std::string &string) {
  string = "\0";
  return 1;
}
