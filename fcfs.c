#include<stdio.h>


void sortProcesses(int n,int pid[],int at[],int bt[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(at[j]>at[j+1]){
                int temp;
                temp = at[j];
                at[j]=at[j+1];
                at[j+1]=temp;

                temp = bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

                temp = pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=temp;
            }
        }
    }
}
void calculate(int n,int at[],int bt[],int ct[],int tat[],int wt[],int pid[]){
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    int total_tat =0;
    int total_wt = 0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_tat+=tat[i];
        total_wt+=wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    float avg_tat = total_tat/n;
    float avg_wt = total_wt/n;
    printf("Average tat is %.2f\n",avg_tat);
    printf("Average wt is %.2f\n",avg_wt);
}
void ganttchar(int n,int pid[],int ct[]){
    printf("|");
    for(int i=0;i<n;i++){
        printf(" P%d |",pid[i]);

    }
    printf("\n0");
    for(int i=0;i<n;i++){
        printf("    %d",ct[i]);
    }
}
int main (){
    int n;
    printf("Enter the number of processes :- ");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],pid[n];
    for(int i=0;i<n;i++){
        pid[i]=i+1;
    printf("Enter the arrival time and burst time for process %d :- \n",i+1);
    scanf("%d %d",&at[i],&bt[i]);
    }
    sortProcesses(n,pid,at,bt);
    int current_time =0;
    for(int i=0;i<n;i++){
        if(current_time<at[i]){
            current_time=at[i];
        }
        current_time+=bt[i];
        ct[i]=current_time;
    }
    calculate(n,at,bt,ct,tat,wt,pid);
    ganttchar(n,pid,ct);
}
