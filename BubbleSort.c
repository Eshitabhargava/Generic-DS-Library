#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void BubbleSort(void *collection,int collLen,int elemSize,int (*p2f)(void *,void *))
{
int i,j,k,weight;
void *temp;
void *left,void *right;
temp=malloc(elemSize);
k=collLen-1;
while(k>=0)
{
i=0;
j=1;
while(j<k)
{
left=coll+(i*elemSize);
right=coll+(j*elemSize);
weight=p2f(left,right);
if(weight>0)
{
memcpy(temp,(const void *)left,elemSize);
memcpy(left,(const void *)right,elemSize);
memcpy(right,(const void *)temp,elemSize);
}
i++;
j++;
}
k--;
}
free(temp);
}