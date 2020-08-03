#include <stdio.h>
#ifdef __cplusplus
extern "C"{
#endif
void zApueTestfun(void)
{
  printf("current funcation is %s\n", __FUNCTION__);
  printf("current line is %d\n", __LINE__);
}

void zApueTestfun1(void)
{
  printf("current funcation is %s\n", __FUNCTION__);
  printf("current line is %d\n", __LINE__);
}

#ifdef __cplusplus
}
#endif