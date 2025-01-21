# Program on Linux

```sh
# build
util/docker_build.sh converter/usb_usb/leonardo:lzhang10.magic

# build & flash
util/docker_build.sh converter/usb_usb/leonardo:lzhang10.magic:flash
```

# Program on Mac

Docker does not work for me on mac. Need toinstall native qmk cli then run:

```sh
# build
qmk compile -kb converter/usb_usb/leonardo -km lzhang10.advantage2
# flash
qmk flash -kb converter/usb_usb/leonardo -km lzhang10.advantage2
```

# old Apple Magic keyboard support

These are incorporated in current branch.

All historical commits are available from: `git reflog --no-abbrev`

- last known commit: 559963554499bdaf4780ffb3fb5bb178d7522d79
- parser fix for magic keyboard: 4b6d39f3e5