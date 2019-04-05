#include<stdio.h>

void WaitingTime(int process[],int n,int bt[],int wt[],float at[])
{
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    for (int i=1;i<n;i++)
    {
        service_time[i] = service_time[i-1] + bt[i-1];

        wt[i] = service_time[i]-at[i];

        if (wt[i] < 0)
        wt[i] = 0;
    }
}

void TurnAroundTime(int process[],int n,int bt[],int wt[],int tat[])
{
     for (int i=0;i<n;i++)
        tat[i] = bt[i] + wt[i];
}

void avgTime(int process[],int n,int bt[],float at[])
{
    int wt[n], tat[n];

    WaitingTime(process,n,bt,wt,at);

    TurnAroundTime(process,n,bt,wt,tat);

    printf("Process \t Burst Time \t Arrival Time \t Waiting Time \t Turn-Around Time \t Completion Time \n");
    int total_wt = 0, total_tat = 0;
    for (int i=0;i<n;i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        printf("\nP%d \t\t %d \t\t %f \t\t %d \t\t  %d \t\t %d",i+1,bt[i],at[i],wt[i],tat[i],compl_time);
    }
    printf("\nAverage waiting time =%f",(float)total_wt/(float)n);
    printf("\nAverage turn around time =%f",(float)total_tat/(float)n);
}

int main()
{
    int n;
    printf("How many Processes u want to enter\n");
    scanf("%d",&n);
    int processes[n];
    printf("Enter the processes\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&processes[i]);
    }
    int burst_time[n];
    printf("Enter the burst time/n");
    for(int i=0;i<n;i++)
    {
         scanf("%d",&burst_time[i]);
    }
    float arrival_time[n];
    printf("Enter the arrivial time\n");
    for(int i=0;i<n;i++)
    {
         scanf("%f",&arrival_time[i]);
    }
    avgTime(processes, n, burst_time, arrival_time);
    return 0; 
} 
