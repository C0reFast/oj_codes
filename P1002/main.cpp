#include <iostream>

using namespace std;

struct Student
{
    string name;
    int exam_point;
    int class_point;
    char cadre;
    char west;
    int paper_num;
};

int main()
{
    int n;
    cin >> n;
    Student* stus = new Student[n];
    int* bonus = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>stus[i].name>>stus[i].exam_point>>stus[i].class_point>>stus[i].cadre>>stus[i].west>>stus[i].paper_num;
        bonus[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        if(stus[i].exam_point > 80 && stus[i].paper_num > 0)
            bonus[i] += 8000;
        if(stus[i].exam_point > 85 && stus[i].class_point > 80)
            bonus[i] += 4000;
        if(stus[i].exam_point > 90)
            bonus[i] += 2000;
        if(stus[i].exam_point > 85 && stus[i].west == 'Y')
            bonus[i] += 1000;
        if(stus[i].class_point > 80 && stus[i].cadre == 'Y')
            bonus[i] += 850;
    }
    int max = n-1;
    int sum = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(bonus[i] >= bonus[max])
            max = i;
        sum += bonus[i];
    }
    cout << stus[max].name << endl;
    cout << bonus[max] << endl;
    cout << sum;

    return 0;
}
