#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void selectionSort(void *collection,int collLen,int elemSize,int (*p2f)(void *,void *))
{
int oep,iep,i,j,si,y,weight;
void *temp;
void *left,*right;
oep=collLen-2;
iep=collLen-1;
temp=malloc(elemSize);
i=0;
while(i<=oep)
{
si=i;
j=i+1;
while(j<=iep)
{
left=collection+(j*elemSize);
right=collection+(i*elemSize);
weight=p2f(left,right);
if(weight<0) si=j;
j++;
}
left=collection+(i*elemSize);
right=collection+(si*elemSize);
memcpy(temp,(const void *)left,elemSize);
memcpy(left,(const void *)right,elemSize);
memcpy(right,(const void *)temp,elemSize);
i++;
}
free(temp);
}
