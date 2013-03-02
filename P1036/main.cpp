#include <iostream>

using namespace std;

void work(int values[],int counts[],int n,int value)
{
    for(int i=0;i<n;i++)
    {
        if(values[i]==value||values[i]==-1)
        {
            values[i] = value;
            counts[i]++;
            return;
        }
    }
}

int find_min(int values[],int n)
{
    int min = 0;
    for(int i=0;i<n;i++)
    {
        if(values[i] != -1)
        {
            min = i;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(values[i] < values[min] && values[i] != -1)
            min = i;
    }
    return min;
}

int main()
{
    int n,val;
    cin>>n;
    int *values = new int[n];
    int *counts = new int[n];
    for(int i=0;i<n;i++)
    {
        values[i] = -1;
        counts[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        cin>>val;
        work(values,counts,n,val);
    }

    for(int i=0;i<n;i++)
    {
        int min = find_min(values,n);
        if(values[min] != -1)
        {
            cout<<values[min]<<" "<<counts[min]<<endl;
            values[min] = -1;
        }
    }

    return 0;
}
