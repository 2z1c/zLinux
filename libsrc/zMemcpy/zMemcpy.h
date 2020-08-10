#ifndef __ZMEMCPY_H
#define __ZMEMCPY_H
#ifdef __cplusplus
extern "C"{
#endif

#include<stdint.h>
void NetByteSeqMemCopy(void *Dest, const void *Src, uint8_t Count);

#ifdef __cplusplus
}
#endif

#endif /*!__ZMEMCPY_H*/
