#!/bin/bash
wget -P /a101 https://github.com/fatima-elfat/alx-low_level_programming/blob/master/0x18-dynamic_libraries/liba101.so
rt LD_PRELOAD=/a101/liba101.so
export LD_PRELOAD=/tmp/putshack.so
