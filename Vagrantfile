# -*- mode: ruby -*-
# vi: set ft=ruby :

# Vagrantfile API/syntax version. Don't touch unless you know what you're doing!
VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|

  # Use Ubuntu 14.04 64-bit.
  config.vm.box = "ubuntu/trusty64"

  # Run the provisioning script.
  config.vm.provision :shell, path: "provision.sh"

  config.vm.provider "virtualbox" do |v|

    # Fix for VirtualBox and Ubuntu losing internet connection.
    v.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
    v.customize ["modifyvm", :id, "--natdnsproxy1", "on"]

    # USB filter to pass Tiva C Launchpad to virtual environment.
    v.customize ['modifyvm', :id, '--usb', 'on']
    v.customize ['usbfilter', 'add', '0', '--target', :id, '--name', 'In-Circuit Debug Interface', '--vendorid', '0x1cbe', '--productid', '0x00fd']

  end

end
