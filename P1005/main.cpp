#include <iostream>

using namespace std;

int main()
{
    int t, m;
    cin >> t >> m;
    int* time = new int[m];
    int* values = new int[m];

    for(int i=0;i<m;i++)
        cin >> time[i] >> values[i];

    int* sum = new int[t+1];
    for(int i=0;i<=t;i++)
        sum[t] = 0;

    for(int i=0;i<m;i++)
    {
        for(int j=t;j>=time[i];j--)
            if(sum[j] < (sum[j-time[i]]+values[i]))
               sum[j] = sum[j-time[i]]+values[i];
    }

    cout << sum[t];

    return 0;
}
