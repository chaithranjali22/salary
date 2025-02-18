#include<stdio.h>
#include<string.h>
int main(){
    int i;
    int vechilecount;
    char vechiletype[10];
    printf("enter number of  vechiles :");
    scanf("%d",&vechilecount);
   float collection=0;
    for(i=1;i<= vechilecount;i++){
        printf("Enter vechile type:");
        scanf("%s",vechiletype);
        if(strcmp(vechiletype,"car")==0){
            collection+=50;
        }else if(strcmp(vechiletype,"truck")==0){
              collection+=100;
           }   else if(strcmp(vechiletype,"bike")==0){
              collection+=20;
              } 
    }
        printf("total toll collection:%.2f\n",collection);
        return 0;
        }
        
