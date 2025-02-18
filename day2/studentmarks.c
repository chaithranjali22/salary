#include<stdio.h>
void inputMarks(int *marks,int n){
    printf("Enter marks:");
    for(int i=0;i<n;i++){
        scanf("%d",&marks[i]);
    }
}
    float calculateAverage(int*marks,int n){
        float average;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=marks[i];
        }
        average=(float)sum/(float)n;
        return average;
        }
        int main(){
            int marks[1000];
            int n;
            printf("enter number of students:");
            scanf("%d",&n);
            inputMarks(marks,n);
            float average=calculateAverage(marks,n);
            printf("Average marks:%.2f\n",average);
            return 0;
            
            
    }
        
    
