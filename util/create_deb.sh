#!/bin/sh
# This file must be edited for each new version is more supposed to be a lookup 
# file for commands
#create manpage assumes pandoc installed
pandoc util/man.md -s -t man -o util/cleware-cutter-control

# create the source archive
#cd ../
#tar -czf cleware-cutter-control-0.1.0.tar.gz debian include src util libs CMakeLists.txt LICENSE README.md

# prepare package 
mkdir cleware-cutter-control-0.1.0
tar -xzmf cleware-cutter-control-0.1.0.tar.gz -C cleware-cutter-control-0.1.0
cd cleware-cutter-control-0.1.0
debmake
# launchpad doc says debuild -S -sd delat packages else -sa for new packages 
# source dput ppa:mswarowsky/toybox cleware-cutter-control_0.1.0-1ppa1_source.changes
debuild -S 
cd ../
mv cleware-cutter-control_0.1.0-1_source.changes cleware-cutter-control_0.1.0-1ppa1_source.changes
# signing should already be done by debuild 
# debsign -k 6E5A15F29FF745E4 cleware-cutter-control_0.1.0-1ppa1_source.changes
dput ppa:mswarowsky/toybox cleware-cutter-control_0.1.0-1ppa1_source.changes                                                                                         │N: See apt-secure(8) manpage for repository creation and user configuration details.
