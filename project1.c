#include<iostream>
using namespace std;

struct Node{
	int process;
	Node *next;
}*start=NULL,*end=NULL,*node=NULL;
void inserting(int x){
	node = new Node();
	node->process = x;
	node->next = NULL;
	if(start==NULL){
		start = node;
		end = node;
	}else{
		end->next = node;
		end = node;
	}
}


void del(int n)
{
	
	if(start==NULL)
	{ cout<<"LINK LIST IS EMPTY"<<endl;
	}
	else if(start->process==n)
	{
		start=start->next;
	}
	else
	{ Node *ptr,*prev;
	ptr=start;
	prev=NULL;
	while(ptr!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
		if(ptr->process==n)
		{
			prev->next=ptr->next;
			break;
		}
	}
}
		
}
void SJFavgTime(int burst[],float arrival[],int n)
{
	for(int i=0;i<n;i++)
    { 
	    inserting(i);
    }
   
   float time=0;
   float res[n];
   float finished[n];
   float execute[n];
   int count=0,i=0;
   int p;
   float small;
   for(int i=0;i<n;i++)
   {
        Node* ptr=start;
        small=100;
        while(ptr!=NULL)
        {
		   if(arrival[ptr->process]<=time)
   	  	   {
   	            if(burst[ptr->process]<small)
   	  	        {    
				    small=burst[ptr->process];
   	  	            p=ptr->process;
				}
			}
		
		ptr=ptr->next;
			  
		}
	del(p);	 
 
	res[count++]=p;
     
	finished[p]=time+burst[p];
    execute[p]=time;
	time=time+burst[p]; 
   }
   
   float wait[n];
   float Ta[n];
   for(int i=0;i<n;i++)
   {
   	  wait[i]=execute[i]-arrival[i];
   	  Ta[i]=burst[i]+wait[i];
   }
    cout<<"\n\nFor SJF";
    cout <<"\nProcesses " << " Burst Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time \n";
    float total_wt = 0, total_tat = 0;
    for (int i=0;i<n;i++)
    {
        total_wt = total_wt + wait[i];
        total_tat = total_tat + Ta[i];
        cout << " " <<i+1<<"\t\t"<<burst[i]<< "\t\t"<< arrival[i] << "\t\t" << wait[i] << "\t\t "<< Ta[i] << endl;
    }
     cout << "\nAverage waiting time = "<<(float)total_wt/(float)n;
    cout << "\nAverage turn around time = "<<(float)total_tat/(float)n;
   

}

void SJFavgTime1(int burst[],float arrival[],int n)
{
	for(int i=0;i<n;i++)
    { 
	    inserting(i);
    }
   
   float time=1;
   float res[n];
   float finished[n];
   float execute[n];
   int count=0,i=0;
   int p;
   float small;
   for(int i=0;i<n;i++)
   {
        Node* ptr=start;
        small=100;
        while(ptr!=NULL)
        {
		   if(arrival[ptr->process]<=time)
   	  	   {
   	            if(burst[ptr->process]<small)
   	  	        {    
				    small=burst[ptr->process];
   	  	            p=ptr->process;
				}
			}
		
		ptr=ptr->next;
			  
		}
	del(p);	 
 
	res[count++]=p;
     
	finished[p]=time+burst[p];
    execute[p]=time;
	time=time+burst[p]; 
   }
   
   float wait[n];
   float Ta[n];
   for(int i=0;i<n;i++)
   {
   	  wait[i]=execute[i]-arrival[i];
   	  Ta[i]=burst[i]+wait[i];
   }
    cout<<"\n\nFor SJF with delay time=1";
    cout <<"\nProcesses " << " Burst Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time \n";
    float total_wt = 0, total_tat = 0;
    for (int i=0;i<n;i++)
    {
        total_wt = total_wt + wait[i];
        total_tat = total_tat + Ta[i];
        cout << " " <<i+1<<"\t\t"<<burst[i]<< "\t\t"<< arrival[i] << "\t\t" << wait[i] << "\t\t "<< Ta[i] << endl;
    }
     cout << "\nAverage waiting time = "<<(float)total_wt/(float)n;
    cout << "\nAverage turn around time = "<<(float)total_tat/(float)n;
   

}

void Sort(int process[], int n,int bt[],float at[])
{
   int i, j,temp1,temp2,temp3;
   for (i=0;i<n-1;i++)
   {
       for (j=0;j<n-i-1;j++)
       {
           if (at[j]>at[j+1])
           {
                temp1=at[j];
                at[j]=at[j+1];
                at[j+1]=temp1;

                temp2=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp2;

                temp3=process[j];
                process[j]=process[j+1];
                process[j+1]=temp3;
           }
       }
   }
}


void WaitingTime(int process[],int n,int bt[],float wt[],float at[])
{
    float service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    for(int i=1;i<n;i++)
    {
        service_time[i]=service_time[i-1]+bt[i-1];

        wt[i] = service_time[i]-at[i];

        if (wt[i] < 0)
        wt[i] = 0;
    }
}

void TurnAroundTime(int process[],int n,int bt[],float wt[],float tat[])
{
     for (int i=0;i<n;i++)
        tat[i] = bt[i] + wt[i];
}

void FCFSavgTime(int process[],int n,int bt[],float at[])
{
    float wt[n], tat[n];

    Sort(process,n,bt,at);

    WaitingTime(process,n,bt,wt,at);

    TurnAroundTime(process,n,bt,wt,tat);
    cout<<"\n For FCFS";
    cout <<"\nProcesses " << " Burst Time " << " Arrival Time "<< " Waiting Time " << " Turn-Around Time \n";
    float total_wt = 0, total_tat = 0;
    for (int i=0;i<n;i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " <<i+1<<"\t\t"<<bt[i]<< "\t\t"<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i] << endl;
    }
     cout << "\nAverage waiting time = "<<(float)total_wt/(float)n;
    cout << "\nAverage turn around time = "<<(float)total_tat/(float)n;
}

int main()
{
    int n;
    cout<<"How many Processes u want to enter\n";
    cin>>n;
    int processes[n];
    cout<<"Enter the processes\n";
    for(int i=0;i<n;i++)
    {
        cin>>processes[i];
    }
    int burst_time[n];
    cout<<"Enter the burst time/n";
    for(int i=0;i<n;i++)
    {
         cin>>burst_time[i];
    }
    float arrival_time[n];
    cout<<"Enter the arrivial time\n";
    for(int i=0;i<n;i++)
    {
         cin>>arrival_time[i];
    }
    FCFSavgTime(processes, n, burst_time, arrival_time);
    SJFavgTime(burst_time,arrival_time,n);
    SJFavgTime1(burst_time,arrival_time,n);
    return 0; 
}
