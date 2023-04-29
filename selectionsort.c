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
    int min,temp;
    for(int i=0;i<5;i++){
        for(int j=i;j<5;j++){
            if(ar[j]<ar[i]){
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
                display(ar);
            }
            
        }
    }
    printf("FINAL ARRAY AFTER SELETION SORT\n");
    display(ar);
}