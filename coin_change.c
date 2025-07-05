//greedy based problem
#include<stdio.h>
#include<stdlib.h>
int compare(const void* a,const void* b){
    return (*(int*)b - *(int*)a);
}
int change(int coins[],int n,int amount){
    int count = 0;
    for(int i=0;i<n;i++){
        if(amount>=coins[i]){
            int sum = amount/coins[i];
            amount = amount - (sum*coins[i]);
            count = count + sum;
        }
        if(amount == 0){
            break;
        }
    }
    return count;
}
int main(){
    int coins[] = {500,100,200,50,20,10,5,2,1};
    int amount = 2000;
    int n = sizeof(coins)/sizeof(coins[0]);
    qsort(coins,n,sizeof(int),compare);
    int totalchange = change(coins,n,amount);
    printf("%d",totalchange);
}



