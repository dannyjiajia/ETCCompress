//  CompressETCTexture
//
//  Created by DannyHe on 9/16/15.
//  Copyright (c) 2015 DannyHe. All rights reserved.
//

#ifndef __CompressETCTexture__CZlib__
#define __CompressETCTexture__CZlib__
#include <zlib.h>

class ETCCompress
{
public:
    ETCCompress();
    ~ETCCompress();
    static int compressETC(const char * destpath,const char *srcpath);
    static int unCompressETC(const char * destpath,const char *srcpath);
    static uLongf unCompressETC(const char * packData,int packSize,Bytef* &buff);
};

#endif /* defined(__CompressETCTexture__CZlib__) */
