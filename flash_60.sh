#!/bin/sh
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash .build/ymdk_yd60mq_16led_default.hex --force
