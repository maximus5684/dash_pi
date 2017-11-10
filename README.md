DashPi
============

A full vehicle dashboard application framework for the Raspberry Pi.

Requirements
------------

### Hardware ###

* [Raspberry Pi 3](https://www.amazon.com/Raspberry-Model-A1-2GHz-64-bit-quad-core/dp/B01CD5VC92/) [$35]
* [HifiBerry DAC+ RCA](https://www.amazon.com/HiFiBerry-DACPLUS-RCA-DAC-RCA-version/dp/B0147RA2PY/) [$35]
* [MicroSD Card - Class 10](https://www.amazon.com/Sandisk-Ultra-Memory-MicroSDHC-SDSQUNC-032G-AN6IA/dp/B011Z77M0C/) At least 32GB recommended [$15]
* [Mini-Box DCDC-USB Power Supply](http://www.mini-box.com/DCDC-USB) [$55]
* [Mini-Box DCDC-USB Enclosure](http://www.mini-box.com/DCDC-USB-ENCLOSURE) [optional - $4]
* Audio Amplifier with RCA Input - recommend [Lanzar Mini MAX 1600W Amplifier](https://www.amazon.com/LANZAR-MNX460-Mini-Max-MOSFET-Channel/dp/B00NYCMCES) [~$200]
* Amplifier cable kit - recommend [BOSS Audio KIT10](https://www.amazon.com/Audio-Amplifier-Installation-Performance-Interconnect/dp/B0002VM8RU/) [$18]
* [RCA Ground-loop Isolator](https://www.amazon.com/BOSS-Audio-B25N-Ground-Isolator/dp/B000LP4RMG/) [$5 - $7]

### Software ###

* Raspbian Jessie with no GUI

See the docs folder for further information on system setup.

Installation
------------

### Power Supply Configuration ###

To configure the DCDC-USB power supply for automotive PC applications you will
need to set the following jumpers:

* CONFIG jumpers
  * 0 OFF
  * 1 OFF
  * 2 ON
  * 3 OFF
  * 4 OFF
  * 5 ON
  * 6 OFF
  * 7 ON

This will configure the power supply for Automotive mode, 5V output, and a 5 second
shutdown signal delay with a 60 second shutdown wait time. For more information on
jumper configuration, see [the manual](http://resources.mini-box.com/online/PWR-DCDC-USB/PWR-DCDC-USB-manual.pdf).

### Basic Steps (OS-independent) ###

* Remove factory stereo head unit
* Install amplifier within cable-reach of Raspberry Pi
  * Connect wiring harness to factory speaker outputs
  * Connect constant power input to battery
  * Connect turn-on wire to ignition signal from old head unit
* Put together Raspberry Pi, Raspberry Pi Touch Monitor, and HifiBerry DAC+

### Basic Steps - Raspbian Jessie ###

* Install stock Raspbian Jessie on RPi
* Update everything (apt-get, rpi-update)
* Install newer version of PulseAudio to fix drop-out bug (at least v6.0)
* Configure for use as Bluetooth A2DP sink with [Super-Simple-Raspberry-Pi-Audio-Receiver-Install](https://github.com/BaReinhard/Super-Simple-Raspberry-Pi-Audio-Receiver-Install)
* Install [sfml-pi](https://github.com/maximus5684/sfml-pi)
* Build and install Dash Pi
  * cd dash_pi
  * mkdir build && cd build
  * cmake ..
  * make
* Configure RPi to launch Dash Pi on boot

### Basic Steps - Raspbian Stretch ###

* Install stock Raspbian Stretch on RPi
* Update everything (apt-get, rpi-update)
* Install prereqs with install_scripts/install_prereqs.sh
* Run install_scripts/install_bluetooth_raspbian_stretch.sh
* Reboot
* Build and install Dash Pi
  * cd dash_pi
  * mkdir build && cd build
  * cmake ..
  * make
* Configure RPi to launch Dash Pi on boot

Usage
-----

TODO

License
------

See the LICENSE file for various licenses for code from the following projects which
were re-used in whole or part for this project:

* BluePlayer [https://github.com/Douglas6/blueplayer] - Bluetooth A2DP and AVRCP Functions
* POTSBLIZ [https://github.com/long-exposure/potsbliz-src] - Bluetooth HFP Functions
* PyOBEX [https://bitbucket.org/dboddie/pyobex] - Bluetooth PBAP Functions

The primary project is licensed under the GNU GPLv3.

Acknowledgements
-----

Most icons created by [Alex Auda Samora from Noun Project](https://thenounproject.com/razerk/uploads/). Used under Creative Commons.
