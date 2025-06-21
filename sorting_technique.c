#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    return (*(int*)a) - (*(int *)b);  //(a - b) for ascending order, (b - a) for descending order
}
int main(){
    int a[] = {100,300,50,20,40,80,10,1000};
    int n = sizeof(a)/sizeof(a[0]);
    qsort(a,n,sizeof(int),compare);
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}
