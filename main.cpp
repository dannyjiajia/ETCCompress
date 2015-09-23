//
//  main.cpp
//  CompressETCTexture
//
//  Created by DannyHe on 9/16/15.
//  Copyright (c) 2015 DannyHe. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "ETCCompress.h"
int main(int argc, const char * argv[]) {
    if (argc != 4)
    {
        printf("Help:\nCompressETCTexture options srcpath outpath\n");
        printf("options:\npack -- pack the file\n");
        printf("unpack -- unpack the file\n");
        printf("example:\n");
        printf("CompressETCTexture pack ~/Desktop/origin.png ~/Desktop/compressed.png\n");
        printf("CompressETCTexture unpack ~/Desktop/compressed.png ~/Desktop/uncompressed.png\n");
        return -1;
    }
    std::string options = argv[1];
    std::string srcpath = argv[2];
    std::string outpach = argv[3];
    
    if (options == "pack")
    {
        printf("ETCCompress:: pack file:%s\n",srcpath.c_str());
        ETCCompress::compressETC(outpach.c_str(),srcpath.c_str());
    }else if (options == "unpack")
    {
        printf("ETCCompress:: unpack file:%s\n",srcpath.c_str());
        ETCCompress::unCompressETC(outpach.c_str(), srcpath.c_str());
    }
    return 0;
}
