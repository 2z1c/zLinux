#include <iostream>
#include <stdio.h>
#include "test.h"
using namespace std;
typedef unsigned char uint8;
/*!字节序转化*/
static void NetByteSeqMemCopy(void *Dest, const void *Src, uint8 Count)
{
    uint8 index = Count - 1;
    uint8 *pDest = (uint8 *)Dest;
    uint8 *pSrc = (uint8 *)Src;
    for (uint8 i = 0x00; i < Count; i++)
    {
        pDest[i] = pSrc[index--];
    }
}
int main()
{
    float testfloat = 1.001;
    uint8 TestArray[4] ;
    NetByteSeqMemCopy(TestArray,&testfloat,sizeof(testfloat));
    for(int i=0x00;i<sizeof(testfloat);i++)
    {
        printf("0x%x ",TestArray[i]);
    }
    printf("Hello, world!!!!!!!\n");
    return 0;
}