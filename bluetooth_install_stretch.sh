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

echo "PRETTY_HOSTNAME=$BT_NAME" >> /tmp/machine-info
tst sudo cp /tmp/machine-info /etc

tst sudo cp install_scripts/bluetooth-agent /etc/init.d
tst sudo chmod +x /etc/init.d/bluetooth-agent
tst sudo update-rc.d bluetooth-agent defaults

tst sudo cp install_scripts/bluez-udev /usr/local/bin
tst sudo chmod 755 /usr/local/bin/bluez-udev

tst sudo cp install_scripts/simple-agent.autotrust /usr/local/bin
tst sudo chmod 755 /usr/local/bin/simple-agent.autotrust

sudo patch /boot/config.txt << EOT
@@ -54,3 +54,6 @@
 
 # Enable audio (loads snd_bcm2835)
 dtparam=audio=on
+
+# High Quality audio patch
+audio_pwm_mode=2
EOT

if [ -f /etc/udev/rules.d/99-com.rules ]; then

sudo patch /etc/udev/rules.d/99-com.rules << EOT
***************
*** 1 ****
--- 1,2,3 ----
  SUBSYSTEM=="input", GROUP="input", MODE="0660"
+ KERNEL=="input[0-9]*", RUN+="/usr/local/bin/bluez-udev"
+ ACTION=="add", KERNEL=="hci0", ENV{SYSTEMD_WANTS}+="bluealsa.service"
EOT

else

tst sudo touch /etc/udev/rules.d/99-com.rules
tst sudo chmod 666 /etc/udev/rules.d/99-com.rules
sudo cat  << EOT > /etc/udev/rules.d/99-input.rules
SUBSYSTEM=="input", GROUP="input", MODE="0660"
KERNEL=="input[0-9]*", RUN+="/usr/local/bin/bluez-udev"
EOT

fi

tst sudo chmod 644 /etc/udev/rules.d/99-com.rules

sudo patch /etc/bluetooth/main.conf << eot
***************
*** 7,8 ****
--- 7,9 ----
  #name = %h-%d
+ name = ${bt_name}

***************
*** 11,12 ****
--- 12,14 ----
  #class = 0x000100
+ class = 0x200414

***************
*** 15,17 ****
  # 0 = disable timer, i.e. stay discoverable forever
! #discoverabletimeout = 0

--- 17,19 ----
  # 0 = disable timer, i.e. stay discoverable forever
! discoverabletimeout = 0
eot

sleep 3

echo "Finished!"
