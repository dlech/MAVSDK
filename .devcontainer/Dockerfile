# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.205.2/containers/debian/.devcontainer/base.Dockerfile

# [Choice] Debian version (use bullseye or stretch on local arm64/Apple Silicon): bullseye, buster, stretch
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# https://stackoverflow.com/a/56748289
ARG VARIANT

# setup custom apt repository
RUN mkdir -p /usr/local/share/keyrings && gpg --list-keys \
    && gpg --no-default-keyring --keyring /usr/local/share/keyrings/skywrangler-archive-keyring.gpg \
    --keyserver keyserver.ubuntu.com --recv-keys B9B2C01AE12272D7 \
    && echo "deb [signed-by=/usr/local/share/keyrings/skywrangler-archive-keyring.gpg] http://archive.ablerobots.com/skywrangler $VARIANT main" > /etc/apt/sources.list.d/skywrangler.list

# install depedencies
RUN dpkg --add-architecture armhf && apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends build-essential g++-arm-linux-gnueabihf cmake pkg-config python3-future  \
    libjsoncpp-dev libcurl4-openssl-dev libtinyxml2-dev libssl-dev libgrpc++-dev \
    zlib1g-dev libprotobuf-dev libc-ares-dev libabsl-dev libre2-dev libupb-dev \
    libjsoncpp-dev:armhf libcurl4-openssl-dev:armhf libtinyxml2-dev:armhf libssl-dev:armhf libgrpc++-dev:armhf \
    zlib1g-dev:armhf libprotobuf-dev:armhf libc-ares-dev:armhf libabsl-dev:armhf libre2-dev:armhf libupb-dev:armhf \
    devscripts debhelper git-buildpackage dput lintian bash-completion

COPY aarch64-linux-gnu/cmake/grpc/ /usr/lib/aarch64-linux-gnu/cmake/grpc/
COPY arm-linux-gnueabihf/cmake/grpc/ /usr/lib/arm-linux-gnueabihf/cmake/grpc/
COPY x86_64-linux-gnu/cmake/grpc/ /usr/lib/x86_64-linux-gnu/cmake/grpc/
COPY devscripts.conf /etc/
COPY dput.cf /etc/
COPY git-to-deb.sh /etc/profile.d/
