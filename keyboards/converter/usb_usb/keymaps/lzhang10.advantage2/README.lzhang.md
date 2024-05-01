# Program

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

# TODO