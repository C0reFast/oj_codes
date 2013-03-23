#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char start1, start2, end1, end2;
        cin >> start1 >> start2 >> end1 >> end2;
        int x = abs(start1 - end1);
        int y = abs(start2 - end2);
        if(x == 0 && y == 0)
        {
            cout << "0 0 0 0 " << endl;
            continue;
        }
        //the king
        cout << max(x,y) << " ";
        //the queen
        if(x==y || x==0 || y==0)
            cout <<"1 ";
        else
            cout <<"2 ";
        //the rook
        if(x==0 || y==0)
            cout <<"1 ";
        else
            cout <<"2 ";
        //the bishop
        if(x == y)
            cout << "1" << endl;
        else if((x+y)%2 != 0)
            cout << "Inf" << endl;
        else
            cout<< "2" << endl;


    }
    return 0;
}
