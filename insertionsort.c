#include<stdio.h>
void display(int ar[]){
    for(int i=0;i<5;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
}

int main()
{
    int ar[5]={1,4,3,2,6};
    for(int i=1;i<5;i++){
        int j=i-1;
        int k=i;
        while(ar[k]<ar[j] && j>=0){
            int temp=ar[k];
            ar[k]=ar[j];
            ar[j]=temp;
            k--;
            j--;
        }
        display(ar);
    }
    
}