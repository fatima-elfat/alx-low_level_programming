#!/bin/bash
wget -P /h https://github.com/fatima-elfat/alx-low_level_programming/blob/master/0x18-dynamic_libraries/101-h.so
export LD_PRELOAD=/h/101-h.so
