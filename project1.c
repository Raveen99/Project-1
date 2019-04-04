#include<stdio.h>

void WaitingTime(int process[],int n,int bt[],int wt[])
{
    wt[0] = 0;

    for (int i=1;i<n;i++)
        wt[i] =  bt[i-1] + wt[i-1];
}
void TurnAroundTime(int process[],int n,int bt[],int wt[],int tat[])
{

    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void avgTime(int process[],int n,int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    WaitingTime(process, n, bt, wt);

    TurnAroundTime(process, n, bt, wt, tat);

    printf("Process----BurstTime----WaitingTime----TurnAround Time\n");

    for (int i=0;i<n;i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" P%d\t\t%d\t\t%d  \t\t%d \n",i+1,bt[i],wt[i],tat[i]);
    }

     printf("\nAverage turn around time =%f",(float)total_tat/(float)n);
}

int main()
{
    int processes[] = {1,2,3};
    int n = 3;
    int  burst_time[] = {8,4,1};
    avgTime(processes,n,burst_time);
    return 0;
}
