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
* Audio Amplifier with RCA Input [$50 - $200]
* Amplifier cable kit - recommend [BOSS Audio KIT10](https://www.amazon.com/Audio-Amplifier-Installation-Performance-Interconnect/dp/B0002VM8RU/) [$18]
* [RCA Ground-loop Isolator](https://www.amazon.com/BOSS-Audio-B25N-Ground-Isolator/dp/B000LP4RMG/) [$5 - $7]

### Software ###

* Raspbian Jessie with PIXEL Desktop
* BlueZ 5
* PulseAduio 5

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
jumper configuration, see the manual here:

http://resources.mini-box.com/online/PWR-DCDC-USB/PWR-DCDC-USB-manual.pdf

### Basic Steps ###

* Remove factory stereo head unit
* Install amplifier within cable-reach of Raspberry Pi
  * Connect wiring harness to factory speaker outputs
  * Connect constant power input to battery
  * Connect turn-on wire to ignition signal from old head unit

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
