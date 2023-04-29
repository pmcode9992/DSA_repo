#include<stdio.h>
void display(int ar[]){
    for(int i=0;i<5;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
}
void mergesort(int ar[],int l, int r, int m){
    int n1=m-l+1;
    int n2=r-m+1;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=ar[i];
    }
    for(int i=0;i<n2;i++){
        R[i]=ar[i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            ar[k]=L[i];
            i++;
        }
        else{
            ar[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        ar[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        ar[k]=R[j];
        k++;
        j++;
    }
    
    
}
void merge(int ar[],int l,int r){
    if (l<r)
    {
    int m=(l+r)/2;
    merge(ar,l,m);
    merge(ar,m+1,r);
    mergesort(ar,l,r,m);
    }
}
int  main()
{
    int ar[5]={1,4,3,2,6};
    merge(ar,0,5-1);
    display(ar);    
}