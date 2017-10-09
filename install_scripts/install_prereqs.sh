#!/bin/bash
sudo apt update

#Prereqs for sdbusplus
sudo apt install autoconf libtool libsystemd-dev autoconf-archive python-yaml
pip install inflection

#Prereqs for sfml-pi
sudo apt install python-bluez cmake libflac-dev libogg-dev libvorbis-dev libopenal-dev libjpeg8-dev libfreetype6-dev libudev-dev libraspberrypi-dev

sudo rm -rf depends
mkdir depends && cd depends

echo ""
echo "Installing sdbusplus..."
echo ""
sleep 2

git clone https://github.com/openbmc/sdbusplus
cd sdbusplus
./bootstrap.sh
./configure
make
sudo make install
cd ..

echo ""
echo "Installing sfml-pi..."
echo ""
sleep 2

git clone https://github.com/mickelson/sfml-pi
cd sfml-pi
mkdir build && cd build
cmake .. -DSFML_RPI=1 -DEGL_INCLUDE_DIR=/opt/vc/include -DEGL_LIBRARY=/opt/vc/lib/libEGL.so -DGLES_INCLUDE_DIR=/opt/vc/include -DGLES_LIBRARY=/opt/vc/lib/libGLESv1_CM.so
make
sudo make install
sudo ldconfig
cd ..

cd ..

echo ""
echo "All done!"
