#!/bin/bash

read -p "Bluetooth device name: " BT_NAME

function tst
{
  echo "===> Executing: $*"
  if ! $*; then
    echo "Exiting script due to error from: $*"
    exit 1
  fi
}

tst sudo cp install_scripts/volume-watcher.py /usr/local/bin/volume-watcher.py
tst sudo chmod +x /usr/local/bin/volume-watcher.py
tst sudo cp install_scripts/volume-watcher.service /lib/systemd/system/volume-watcher.service
tst sudo systemctl enable volume-watcher

tst sudo cp install_scripts/bluealsa-aplay@.service /lib/systemd/system/bluealsa-aplay@.service

echo "PRETTY_HOSTNAME=$BT_NAME" >> /tmp/machine-info
tst sudo cp /tmp/machine-info /etc

#tst sudo cp install_scripts/bluetooth-agent /etc/init.d
#tst sudo chmod +x /etc/init.d/bluetooth-agent
#tst sudo update-rc.d bluetooth-agent defaults

tst sudo cp install_scripts/bluez-udev /usr/local/bin
tst sudo chmod 755 /usr/local/bin/bluez-udev

#tst sudo cp install_scripts/simple-agent.autotrust /usr/local/bin
#tst sudo chmod 755 /usr/local/bin/simple-agent.autotrust

tst sudo cp install_scripts/a2dp-autoconnect /usr/local/bin
tst sudo chmod 755 /usr/local/bin/a2dp-autoconnect

sudo patch /boot/config.txt << EOT
--- a/config.txt.orig
+++ b/config.txt
@@ -53,4 +53,7 @@ disable_overscan=0
 # Additional overlays and parameters are documented /boot/overlays/README
 
 # Enable audio (loads snd_bcm2835)
-dtoverlay=audio=on
+
+start_x=0
+dtoverlay=pi3-disable-wifi
+dtoverlay=hifiberry-dacplus
EOT

if [ -f /etc/udev/rules.d/99-com.rules ]; then

sudo patch /etc/udev/rules.d/99-com.rules << EOT
--- 99-com.rules.orig	2016-03-21 13:43:23.000000000 +0000
+++ 99-com.rules	2017-10-09 04:47:30.295659049 +0000
@@ -1,4 +1,7 @@
 SUBSYSTEM=="input", GROUP="input", MODE="0660"
+KERNEL=="input[0-9]*", RUN+="/usr/local/bin/bluez-udev"
+KERNEL=="input[0-9]*", RUN+="/usr/local/bin/a2dp-autoconnect"
+ACTION=="add", KERNEL=="hci0", ENV{SYSTEMD_WANTS}+="bluealsa.service"
 SUBSYSTEM=="i2c-dev", GROUP="i2c", MODE="0660"
 SUBSYSTEM=="spidev", GROUP="spi", MODE="0660"
 SUBSYSTEM=="bcm2835-gpiomem", GROUP="gpio", MODE="0660"
EOT

else

tst sudo touch /etc/udev/rules.d/99-com.rules
tst sudo chmod 666 /etc/udev/rules.d/99-com.rules
sudo cat  << EOT > /etc/udev/rules.d/99-input.rules
SUBSYSTEM=="input", GROUP="input", MODE="0660"
KERNEL=="input[0-9]*", RUN+="/usr/local/bin/bluez-udev"
KERNEL=="input[0-9]*", RUN+="/usr/local/bin/a2dp-autoconnect"
ACTION=="add", KERNEL=="hci0", ENV{SYSTEMD_WANTS}+="bluealsa.service"
EOT

fi

tst sudo chmod 644 /etc/udev/rules.d/99-com.rules

sudo patch /etc/bluetooth/main.conf << eot
--- main.conf.orig	2017-04-05 11:33:37.000000000 +0000
+++ main.conf	2017-10-09 04:45:38.856824827 +0000
@@ -2,16 +2,16 @@
 
 # Default adapter name
 # Defaults to 'BlueZ X.YZ'
-#Name = BlueZ
+Name = raspberrypi
 
 # Default device class. Only the major and minor device class bits are
 # considered. Defaults to '0x000000'.
-#Class = 0x000100
+Class = 0x200414
 
 # How long to stay in discoverable mode before going back to non-discoverable
 # The value is in seconds. Default is 180, i.e. 3 minutes.
 # 0 = disable timer, i.e. stay discoverable forever
-#DiscoverableTimeout = 0
+DiscoverableTimeout = 0
 
 # How long to stay in pairable mode before going back to non-discoverable
 # The value is in seconds. Default is 0.
eot

sleep 3

echo "Finished!"
