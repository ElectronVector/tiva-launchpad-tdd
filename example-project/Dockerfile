FROM ubuntu:18.04

WORKDIR /app

RUN apt-get update && apt-get install -y ruby gcc curl make
RUN gem install ceedling

# Install the GCC ARM embedded toolchain.
WORKDIR /tmp
RUN curl -O https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/8-2019q3/RC1.1/gcc-arm-none-eabi-8-2019-q3-update-linux.tar.bz2 \
    && tar xvf gcc-arm-none-eabi-8-2019-q3-update-linux.tar.bz2 -C /usr/local/
ENV PATH="${PATH}:/usr/local/gcc-arm-none-eabi-8-2019-q3-update/bin"

WORKDIR /app

