#include <stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    int b[n],p[n],index[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&b[i],&p[i]);
        index[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        int a=p[i],m=i;
        for(int j=i;j<n;j++)
        {
            if(p[j] < a)
            {
                a=p[j];
                m=j;
            }
        }
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i],&index[m]);
    }
    int t=0;
    printf("Order of process Execution is\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",index[i],t,t+b[i]);
        t+=b[i];
    }
    printf("\n");
    printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time=0;
    float twt=0.0;
    float tat= 0.0;
    for(int i=0;i<n;i++)
    {
        printf("P%d          \t%d          \t%d          \t%d\n",index[i],b[i],wait_time,wait_time + b[i]);
        twt += wait_time;
        tat += (wait_time+b[i]);
        wait_time += b[i];
    }
         float att,awt;
    awt = twt/n;
    att = tat/n;
    printf("     Avg. waiting time    = %f\n",awt);
    printf("     Avg. turnaround time = %f\n",att);
    return 0;
}
