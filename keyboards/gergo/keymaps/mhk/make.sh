#!/bin/bash
set -e
git clone https://github.com/qmk/qmk_firmware.git
cp -r ~/mhk qmk_firmware/keyboards/gergo/keymaps
cd qmk_firmware
./util/qmk_install.sh
make git-submodule
make gergo:mhk:dfu
