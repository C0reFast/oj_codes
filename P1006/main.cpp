#include <iostream>

using namespace std;

int main()
{
    char isbn[13];
    cin >> isbn;
    int sum = 0;
    sum += isbn[0] - '0';
    for(int i=0;i<3;i++)
        sum += (isbn[i+2] - '0') * (i + 2);
    for(int i=0;i<5;i++)
        sum += (isbn[i+6] - '0') * (i + 5);
    int hash = sum % 11;
    if(hash == isbn[12]-'0')
        cout<<"Right"<<endl;
    else if(hash==10 && isbn[12]=='X')
        cout<<"Right"<<endl;
    else
    {
        if(hash == 10)
            isbn[12] = 'X';
        else
            isbn[12] = hash+'0';
        cout<<isbn<<endl;
    }

    return 0;
}
