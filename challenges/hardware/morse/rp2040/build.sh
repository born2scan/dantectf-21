#!/bin/bash
set -e

cd build
if [ ! -d CMakeFiles ]; then
    cmake ..
fi
make -j 4
echo "Waiting for RP2040..."
while [ ! -d /run/media/nmaggioni/RPI-RP2 ]; do
    sleep 0.5
done
echo "RP2040 ready"
sleep 1
acp -g pio_morse.uf2 /run/media/nmaggioni/RPI-RP2/
echo "Done!"