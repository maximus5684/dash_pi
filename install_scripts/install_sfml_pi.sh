#!/bin/bash
rm -rf sfml-pi
git clone https://github.com/mickelson/sfml-pi
cd sfml-pi
mkdir build && cd build
cmake .. -DSFML_RPI=1 -DEGL_INCLUDE_DIR=/opt/vc/include -DEGL_LIBRARY=/opt/vc/lib/libEGL.so -DGLES_INCLUDE_DIR=/opt/vc/include -DGLES_LIBRARY=/opt/vc/lib/libGLESv1_CM.so
make
sudo make install
sudo ldconfig
cd ..
