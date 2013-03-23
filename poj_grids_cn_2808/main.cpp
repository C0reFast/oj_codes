#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n++;
    bool* trees = new bool[n];
    for(int i=0;i<n;i++)
        trees[i] = true;
    int m;
    cin >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        while(x <= y)
        {
            trees[x] = false;
            x++;
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(trees[i])
            sum++;
    }
    cout << sum;
    return 0;
}
