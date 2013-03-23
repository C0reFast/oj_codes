#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string* input = new string[n];
    for(int i=0;i<n;i++)
        cin>>input[i];

    for(int i=0;i<n;i++)
    {
        char last = input[i][input[i].length()-1];
        if((last - '0')%2 == 0)
            cout<<"even"<<endl;
        else
            cout<<"odd"<<endl;
    }

    return 0;
}
