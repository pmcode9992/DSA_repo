#include<stdio.h>
void display(int ar[]){
    for(int i=0;i<6;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
}
void compare(int *a ,int *b){
    if(*a>*b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
}
int main()
{
    int ar[6]={1,7,3,2,6,4};
    display(ar);
    int gap=6/2;
    int temp=gap;
    while(gap>=1){
        printf("gap = %d\n",gap);
        for(int i=0;i<6-gap;i++){
            compare(&ar[i],&ar[gap+i]);
            display(ar);
        }
        gap=gap-1;   
    }
}