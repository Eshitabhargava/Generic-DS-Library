#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *collection,int lb,int ub,int elemSize,int (*p2f)(void *,void *))
{
int y,z;
void *temp;
temp=malloc(elemSize);
for(y=lb+1;y<=ub;++y)
{
memcpy(temp,(const void *)(collection+(y*elemSize)),elemSize);
for(z=y-1;z>=lb && p2f(collection+(z*elemSize),temp)>0;--z) memcpy(collection+((z+1)*elemSize),(const void *)(collection+(z*elemSize)),elemSize);
memcpy(collection+((z+1)*elemSize),(const void *)temp,elemSize);
}
free(temp);
}