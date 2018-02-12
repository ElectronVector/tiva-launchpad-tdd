#!/bin/bash

# This is the provisioning script which is executed when the virtual machine is first created.
# Here is where we install all of the dependencies for our project.

export DEBIAN_FRONTEND=noninteractive

VERSION_CEEDLING=0.18.0
#VERSION_GNU_ARM=4.9.3.2015q1-0trusty13

resize2fs /dev/sda1

apt-get update

apt-get install -y ruby

# Rake is a dependency for projects built with Ceedling.
# apt-get -y install rake
gem install ceedling --version $VERSION_CEEDLING

# Some other tools we might want to use in the future.
apt-get -y install doxygen
apt-get -y install splint
apt-get -y install pandoc

# Developer tools.
apt-get -y install git
# apt-get -y install subversion

# Install the pre-built GNU ARM tools (including the compiler).
# apt-get -y remove binutils-arm-none-eabi gcc-arm-none-eabi
# apt-add-repository -y ppa:terry.guo/gcc-arm-embedded
# apt-get update
apt-get -y install build-essential
apt-get -y install gcc-arm-none-eabi

# Install TivaWare and build.

# Install lm4flash.
apt-get -y install libusb-1.0.0
apt-get -y install pkg-config
git clone git://github.com/utzig/lm4tools.git /usr/local/lm4tools
pushd /usr/local/lm4tools/lm4flash
make
popd

# Create a configuration file in /etc/udev/rules.d to allow access to the USB device needed for programming.
PROG_CONF_FILE=/etc/udev/rules.d/tiva-c-launchpad.rules
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="1cbe", ATTR{idProduct}=="00fd", OWNER="vagrant", MODE="0666"' > $PROG_CONF_FILE

# Create a script in /etc/profile.d which will automatically be run upon login. We'll set our path
# and any other environment variables here.
SETUP_SCRIPT=/etc/profile.d/setup-environment.sh
echo "export PATH=$PATH:/usr/local/lm4tools/lm4flash" > $SETUP_SCRIPT

# Have the script start us in the host-shared folder.
echo "cd /vagrant" >> $SETUP_SCRIPT
