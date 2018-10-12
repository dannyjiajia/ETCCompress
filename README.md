# ETCCompress

Compress the etc format texture with zlib.

## How to use 

compress file

~~~
    CompressETCTexture pack ~/Desktop/test.pvr ~/Desktop/compressed.pvr
~~~

uncompress file

~~~
    CompressETCTexture unpack ~/Desktop/compressed.pvr ~/Desktop/test_compressed.pvr
~~~

## How to build 

### Mac 

build for xcode

~~~
mkdir build
cd build
cmake -G "Xcode" ..
~~~

### Windows

build for vs2013 (only for win32)

~~~
mkdir build
cd build
cmake -G "Visual Studio 12 2013" ..
~~~
