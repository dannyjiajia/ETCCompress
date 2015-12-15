//
//  CompressETCTexture
//
//  Created by DannyHe on 9/16/15.
//  Copyright (c) 2015 DannyHe. All rights reserved.
//

#include "ETCCompress.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ZipHeaderInfo
{
    char sig[4];
    int fileSize;
};

int ETCCompress::compressETC(const char * destpath,const char *srcpath)
{
    ZipHeaderInfo zipHeader;
    
    
    FILE* inFile = fopen(srcpath, "rb");
    
    if(!inFile)
    {
        return -1;
    }
    
    fseek(inFile, 0, SEEK_END);
    int fileSize = ftell(inFile);
    char * fileData = new char[fileSize];
    fseek(inFile, 0, SEEK_SET);
    fread(fileData, 1, fileSize, inFile);
    fclose(inFile);
    zipHeader.fileSize = fileSize;
    zipHeader.sig[0] = '!';
    zipHeader.sig[1] = 'E';
    zipHeader.sig[2] = 'T';
    zipHeader.sig[3] = 'C';
    
    uLongf destLength = compressBound(fileSize);

    Bytef* pDestBuf = new Bytef[destLength];
    int result = compress2(pDestBuf , &destLength, (const Bytef*)fileData, fileSize,9);
    if (result != Z_OK)
    {
        switch(result)
        {
            case Z_MEM_ERROR:
                printf("ETCCompress:: note enough memory for compression");
                break;
                
            case Z_BUF_ERROR:
                printf("ETCCompress:: note enough room in buffer to compress the data");
                break;
        }
        return -1;
    }
    
    cout << "ETCCompress:: orignal size: " << fileSize << " bytes"
    << " , compressed size : " << destLength << " bytes"
    << " , header size: " << sizeof(zipHeader) << " bytes"
    << " , final size : " << sizeof(zipHeader) + destLength << " bytes"
    << " , compress ratio:" << (1 - (double)(sizeof(zipHeader) + destLength)/fileSize)*100 << "%"
    << '\n';
    
    
    FILE* fo = fopen(destpath, "wb+");
    if(fo)
    {
        fwrite(&zipHeader, sizeof(zipHeader), 1, fo);
        fwrite(pDestBuf,destLength, 1, fo);
        fclose(fo);
        delete [] pDestBuf;
        
        return 0;
    }
    return 0;
}

uLongf ETCCompress::unCompressETC(const char * packData,int packSize,Bytef* &buff)
{
    struct ZipHeaderInfo *header = (struct ZipHeaderInfo*) packData;
    if (!(header->sig[0] == '!' && header->sig[1] == 'E' && header->sig[2] == 'T' && header->sig[3] == 'C')) {
        printf("\nETCCompress:: header error");
        return -1;
    }
    int orginSize = header->fileSize;
    int headerSize = sizeof(*header);
    uLongf newSize = orginSize;
    Bytef* pUnBuf = new Bytef[newSize];
    int result2 = uncompress(pUnBuf, &newSize,(const Bytef*)packData + headerSize,packSize - headerSize);
    if (result2 != Z_OK)
    {
        switch(result2)
        {
            case Z_MEM_ERROR:
                printf("ETCCompress:: note enough memory for uncompression");
                break;
                
            case Z_BUF_ERROR:
                printf("ETCCompress:: note enough room in buffer to uncompress the data");
                break;
        }
        return -1;
    }
    buff = pUnBuf;
    cout << "orignal size: " << packSize << " bytes" 
    << " , ucompressed size : " << orginSize << " bytes" << '\n';
    return newSize;
}

int ETCCompress::unCompressETC(const char *destpath, const char *srcpath)
{
    FILE* packFile = fopen(srcpath, "rb");
    
    fseek(packFile, 0, SEEK_END);
    int packSize = ftell(packFile);
    char * packData = new char[packSize];
    fseek(packFile, 0, SEEK_SET);
    fread(packData, 1, packSize, packFile);
    fclose(packFile);
    Bytef* pUnBuf;
    uLongf newSize = unCompressETC(packData,packSize,pUnBuf);
    if (newSize == -1)
    {
        printf("\nETCCompress:: uncompress error!");
        return -1;
    }
    
    FILE* ft = fopen(destpath, "wb+");
    if(ft)
    {
        fwrite(pUnBuf,newSize, 1, ft);
        fclose(ft);
        delete [] pUnBuf;
        return 0;
    }

    return -1;
}