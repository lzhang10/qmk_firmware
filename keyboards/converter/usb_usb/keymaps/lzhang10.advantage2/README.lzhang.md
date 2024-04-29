# Program

First set secret in secret_var.h, this will not be committed to git
```
# build
util/docker_build.sh converter/usb_usb/leonardo:lzhang10.advantage2

# build & flash
util/docker_build.sh converter/usb_usb/leonardo:lzhang10.advantage2:flash
```

# TODO

switch to native qmk case word implementation