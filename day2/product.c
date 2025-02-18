#include<stdio.h>
int main(){
    int i;
    int productcount;
    int weight;
    printf("enter number of products:");
    scanf("%d",&productcount);
    int acceptedcount=0;
    int rejectedcount=0;
    for(i=1;i<=productcount;i++){
        printf("Enter weights(in grams):");
        scanf("%d",&weight);
        if(weight>=950&&weight<=1050){
            acceptedcount++;
        }else{
            rejectedcount++;
        }
    }
     printf("Accepted product:%d\n",acceptedcount);
     printf("Rejected product:%d\n",rejectedcount);
     return 0;

    }
    
    
