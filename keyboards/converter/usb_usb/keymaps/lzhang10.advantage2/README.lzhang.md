# Program on Linux

First set secret in secret_var.h, this will not be committed to git
```sh
# build
util/docker_build.sh converter/usb_usb/leonardo:lzhang10.advantage2

# build & flash
util/docker_build.sh converter/usb_usb/leonardo:lzhang10.advantage2:flash
```

If the above docker/podman flash script does not work install avrdude on the host and run:
```sh
sleep 8 && avrdude -p atmega32u4 -c avr109 -P /dev/ttyACM0 -U flash:w:.build/converter_usb_usb_leonardo_lzhang10.advantage2.hex
```

The above command can be found by adding "make VERBOSE=true" to the make command in util/docker_build.sh

# Program on Mac

Docker does not work for me on mac. Need toinstall native qmk cli then run:

```sh
# build
qmk compile -kb converter/usb_usb/leonardo -km lzhang10.advantage2
# flash
qmk flash -kb converter/usb_usb/leonardo -km lzhang10.advantage2
```


# Update qmk

```
git remote add qmk https://github.com/qmk/qmk_firmware.git
git checkout -b lzhang10.qmk-update
git merge qmk/master
# resolve all conflicts then build
# 2025-02-13 qmk/master lzhang10.advantage2 fail to build due to firmware 222 bytes over.
```
