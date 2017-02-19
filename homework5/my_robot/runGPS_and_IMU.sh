#!/bin/bash
./gen_types.sh

export CLASSPATH=$PWD/exlcm
export LCM_DEFAULT_URL=udpm://?ttl=1

python gpgga-driver.py /dev/ttyl1 & 
python imu-driver.py  /dev/ttyl0 &
lcm-logger -s data/LOL & 
lcm-spy 

kill %1 %2 %3 %4
