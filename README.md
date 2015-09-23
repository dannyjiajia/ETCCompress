#ETCCompress

Compress the etc format texture with zlib.

###### how ...

* compile 

~~~
    cmake .
    make 
~~~

* compress file

~~~
    CompressETCTexture pack ~/Desktop/test.pvr ~/Desktop/compressed.pvr
~~~

* uncompress file

~~~
    CompressETCTexture unpack ~/Desktop/compressed.pvr ~/Desktop/test_compressed.pvr
~~~

* Xcode to edit 

~~~
    cmake . -GXcode
~~~