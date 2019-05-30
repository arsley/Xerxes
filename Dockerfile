FROM ubuntu:18.04 AS build

RUN apt-get update -qq && \
    apt-get install -y build-essential cmake git && \
    apt-get install -y gcc-8 g++-8 && \
    apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
ADD . /tmp/Xerxes
WORKDIR /tmp/Xerxes
RUN sed -i 's/git@github.com:/https:\/\/github.com\//' .gitmodules && \
    git submodule update --init --recursive
RUN CMAKE_CXX_COMPILER=/usr/bin/g++-8 CMAKE_CC_COMPILER=/usr/local/gcc-8 cmake .
RUN make

FROM ubuntu:18.04

COPY --from=build /tmp/Xerxes/bin/Xerxes /opt/Xerxes/
COPY --from=build /tmp/Xerxes/useragents /opt/Xerxes/
RUN apt-get update -qq && \
    apt-get install -y libssl-dev && \
    apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
WORKDIR /opt/Xerxes
ENTRYPOINT ["/bin/bash"]

