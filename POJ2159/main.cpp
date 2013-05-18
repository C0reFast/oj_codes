#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int cmp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    string original, encrypted;
    cin >> encrypted >> original;
    int len = original.length();
    int a[26] = {0};
    int b[26] = {0};
    memset(a,0,len);
    memset(b,0,len);
    for(int i=0;i<len;i++){
        a[original[i] - 'A']++;
        b[encrypted[i] - 'A']++;
    }
    qsort(a,26,sizeof(int),cmp);
    qsort(b,26,sizeof(int),cmp);

    int i;
    for(i=0;i<26;i++)
        if(a[i]!=b[i])
            break;

    if(i>25)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
