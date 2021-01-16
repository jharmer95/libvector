# libvector

A C library implementing a generic vector struct similar to that found in the C++ STL

**NOTE:** This project requires GNU C extensions! (`gnu11` or `gnu17`/`gnu18`), it will not work w/ ISO C (`c11`)

## Building

This project uses Meson. Make sure you have Meson and ninja installed and then from the root project directory:

```shell
meson setup builddir --buildtype=release
```

_Replace "release" with "debug" for debug builds_

```shell
meson compile -C builddir
```

## Installing

Once a release build is compiled run:

```shell
meson install -C builddir
```
