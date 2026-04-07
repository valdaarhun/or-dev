Busybox environment setup for OpenRISC-linux kernel development.

To create an initramfs, run:
```sh
~ $ cd or-dev
~/or-dev $ find . -print0 | cpio -H newc -ov --null --owner=root:root | bzip2 > ../initramfs.cpio.bz2
```

