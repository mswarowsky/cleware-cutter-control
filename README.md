# cleware-cutter-control

A simple tool to control a [cleware USB cutter](https://www.cleware-shop.de/epages/63698188.sf/en_GB/?ViewObjectPath=%2FShops%2F63698188%2FProducts%2F1001%2FSubProducts%2F1001-1).

# Installation from deb package
1. Add the PPA repo `sudo add-apt-repository ppa:mswarowsky/toybox`
1. Update package list `sudo apt-get update`
1. Install package `sudo apt-get install cleware-cutter-control`

# Installation from source
1. Download the [cleware linux libaries](http://www.cleware.info/downloads/german/Linux_Ubuntu_6.0.1.zip)
1. Extract the content to `libs/USBaccess`
1. Make sure you have the [C++ boost libary](https://www.boost.org) installed on your system 
1. Clone the repo `git clone git@github.com:mswarowsky/cleware-cutter-control.git`
1. Install the the udev rules to have access to the device file (needs root permissions) `cp util/99-cleware.rules /etc/udev/rules.d` 
1. Create build folder ` makedir build`
1. Enter build folder `cd build`
1. Call cmake `cmake ..`
1. Call make `make`
1. The executable will be in the src folder


