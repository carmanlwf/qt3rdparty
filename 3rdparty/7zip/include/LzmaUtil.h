#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define MY_STDAPI int __stdcall

#define LZMA_PROPS_SIZE 5

//-------------------------------------------------------------------------------
//Returns:
//  SZ_OK               - 0	OK
//  SZ_ERROR_MEM        - 2	Memory allocation error
//  SZ_ERROR_DATA		- 1	Data error
//  SZ_ERROR_WRITE		- 9
//  SZ_ERROR_READ		- 8
//-------------------------------------------------------------------------------
MY_STDAPI LzmaCompress(char* pSrcFile, char* pDstFile);


//-------------------------------------------------------------------------------
//Returns:
//  SZ_OK               - 0	OK
//  SZ_ERROR_MEM        - 2	Memory allocation error
//  SZ_ERROR_DATA		- 1	Data error
//  SZ_ERROR_WRITE		- 9
//  SZ_ERROR_READ		- 8
//-------------------------------------------------------------------------------
MY_STDAPI LzmaUncompress(char* pSrcFile, char* pDstFile);

#ifdef __cplusplus
}
#endif
