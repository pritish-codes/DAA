#include<stdio.h>


void knapsack(int n,float weight[],float profit[],float capacity){
    float x[20],tp=0 ; //tp denotes total profit 
    int i,j,u;
    u=capacity;
    for(i=0;i<n;i++){
        x[i]=0.0;
    }
    for(i=0;i<n;i++){
        if(weight[i]>u)
        break;
        else{
            x[i]=1.0;
            tp=tp+profit[i];
            u=u-weight[i];
        }
    }
    if(i<n){
        x[i]=u/weight[i];
        }
    tp=tp+(x[i]*profit[i]);
    printf("\n The resultant vector is \n");
    for(i=0;i<n;i++){
        printf("%f\t",x[i]);
    }
    printf("\n Maximum profit is :- %f",tp);
}


int main(){
    float weight[20],profit[20],capacity;
    int num,i,j;
    float ratio[20],temp;

    printf("\n Enter the number of objects :- ");
    scanf("%d", &num);

    printf("\n Enter the weights and profits of each object :- ");
    for(i=0;i<num;i++){
        scanf("%f %f",&weight[i],&profit[i]);

    }

    printf("\n Enter the capacity of the knapsack :- ");
    scanf("%f",&capacity);

    //Calculating Ratio

    for(i=0;i<num;i++){
        ratio[i]=profit[i]/weight[i];
    }

    for(i=0;i<num;i++){
        for(j=i+1;j<num;j++){
            if(ratio[i]<ratio[j]){
                
                temp=ratio[j];
                ratio[j]=ratio[j];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

            }
        }
    }

    knapsack(num,weight,profit,capacity);


}