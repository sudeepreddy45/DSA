#include<stdio.h>
#define n 7
int a[n];
a[n]={2,3,4,5,6,7};
void binarysearch(int key){
    int l = 0;
    int h = n - 1;
    while(l<=h){
        int mid = l + (h-l)/2;
        if(a[mid]==key){
            printf("Key is at %d",mid+1);
            return;
        }
        else if(a[mid]>key){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
}
int main(){
    int key = 6;
    binarysearch(key);
}
