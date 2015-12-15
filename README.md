#ETCCompress

Compress the etc format texture with zlib.

## how to use 


* compress file

~~~
    CompressETCTexture pack ~/Desktop/test.pvr ~/Desktop/compressed.pvr
~~~

* uncompress file

~~~
    CompressETCTexture unpack ~/Desktop/compressed.pvr ~/Desktop/test_compressed.pvr
~~~

## how to build 

### Mac Os

build for xcode

~~~
	mkdir build
	cd build
    cmake -G "Xcode" ..
~~~

### Windows

example:build for vs2013 (only for win32)

~~~
	mkdir build
	cd build
    cmake -G "Visual Studio 12 2013" ..
~~~

~you can build with cmake gui~

---
DannyHe