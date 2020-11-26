#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void linearSort(void *collection,int collLen,int elemSize,int (*p2f)(void *,void *))
{
int oep,iep,i,j,k,y,weight;
void *temp;
void *left,*right;
oep=collLen-2;
iep=collLen-1;
temp=malloc(elemSize);
for(i=0;i<oep;++i)
{
for(j=i+1;j<=iep;++j)
{
left=collection+(i*elemSize);
right=collection+(j*elemSize);
weight=p2f(left,right);
if(weight>0)
{
memcpy(temp,(const void *)left,elemSize);
memcpy(left,(const void *)right,elemSize);
memcpy(right,(const void *)temp,elemSize);
}
}
}
free(temp);
}
