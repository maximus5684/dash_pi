#!/bin/bash
sudo apt update
sudo apt install python-bluez cmake libflac-dev libogg-dev libvorbis-dev libopenal-dev libjpeg8-dev libfreetype6-dev libudev-dev libraspberrypi-dev

rm -rf depends
mkdir depends && cd depends

echo "Installing sdbusplus..."
sleep 2

git clone https://github.com/openbmc/sdbusplus
cd sdbusplus
cd ..

echo "Installing sfml-pi..."
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

echo "All done!"
