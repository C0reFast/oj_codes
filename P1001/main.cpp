#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int compare (const void * a, const void * b)
{
    return ( *(unsigned long*)a - *(unsigned long*)b );
}

void judge(long p)
{
    if(p<2)
    {
        cout<<"NO"<<endl<<p;
        return;
    }
    for (unsigned long i=2;i<=(unsigned long)sqrt((double)p);i++)
    {
        if(p%i==0)
        {
            cout<<"NO"<<endl<<p;
            return;
        }
    }
    cout<<"YES"<<endl<<p;
}
int main()
{
    int n,k;
    cin>>n>>k;
    unsigned long* values = new unsigned long[n];
    for(int i=0;i<n;i++)
        cin>>values[i];
    qsort(values,n,sizeof(unsigned long),compare);
    judge(values[n-k] - values[k-1]);

    return 0;
}
