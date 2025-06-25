#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return (*(int*)a) - (*(int*)b);
}
int main()
{
    int a[] = {10,5,2,5,7,7,7,6};
    int n = sizeof(a)/sizeof(a[0]);
    
    qsort(a,n,sizeof(int),compare);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int temp = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=a[temp]){
            temp++;
            a[temp]=a[i];
        }
    }
    for(int i=0;i<=temp;i++){
        printf("%d ",a[i]);
    }
}
