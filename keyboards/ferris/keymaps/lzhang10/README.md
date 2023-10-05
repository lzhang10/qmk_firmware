
# build & flash

Both sides needed to be flashed ONCE to load the default firmware and set hand

``` sh
# do it for both sides once
util/docker_build.sh ferris/sweep:default:flash

# do it for the left side
util/docker_build.sh ferris/sweep:default:avrdude-split-left
# do it for the right side
util/docker_build.sh ferris/sweep:default:avrdude-split-right
```

# update keymap
Adjust keymap.json and then only need to flash the master side: the one connected to the USB. There is no need to flash the slave side.

``` sh
# build
util/docker_build.sh ferris/sweep:lzhang10

# build & flash
util/docker_build.sh ferris/sweep:lzhang10:flash

```
