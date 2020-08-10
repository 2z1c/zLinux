#include "zMemcpy.h"

void NetByteSeqMemCopy(void *Dest, const void *Src, uint8_t Count)
{
    uint8_t index = Count - 1;
    uint8_t *pDest = (uint8_t *)Dest;
    uint8_t *pSrc = (uint8_t *)Src;
    for (uint8_t i = 0x00; i < Count; i++)
    {
        pDest[i] = pSrc[index--];
    }
}