#include <iostream>
#include <string>

using namespace std;

bool IsPrime(int n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    for(int i=2;i<=n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    string word;
    cin >> word;
    int alpha_sum[26] = {0};
    int length = word.length();
    for(int i=0;i<length;i++)
        alpha_sum[(word[i]-'a')]++;
    int max = alpha_sum[0];
    int min = 100;
    for(int i=0;i<26;i++)
    {
        if(max < alpha_sum[i])
            max = alpha_sum[i];
        if(min > alpha_sum[i] && alpha_sum[i] > 0)
            min = alpha_sum[i];
    }
    if(min == 100)
        min = 0;
    int result = max - min;
    if(IsPrime(result))
        cout<<"Lucky Word"<<endl<<result;
    else
        cout<<"No Answer"<<endl<<0;
    return 0;
}
