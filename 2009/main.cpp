#include <iostream>

using namespace std;

struct data_node
{
    int data;
    data_node* link;
};

bool list_add(data_node* list, int data)
{
    data_node* p = list;
    while(p->link)
        p = p->link;
    data_node* node = new data_node;
    if(!node)
        return false;
    node->data = data;
    node->link = NULL;
    p->link = node;
    return true;
}
bool list_delete(data_node* list, int pos, int& data)
{
    if(pos < 1)
        return false;
    data_node* p = list;
    for(int i=0;i<pos-1;i++)
    {
        p = p->link;
        if(!p)
            return false;
    }
    data_node* tmp = p->link;
    p->link = tmp->link;
    data = tmp->data;
    delete tmp;
    return true;
}

bool list_data(data_node* list, int pos, int& data)
{
     if(pos < 1)
        return false;
    data_node* p = list;
    for(int i=0;i<pos;i++)
    {
        p = p->link;
        if(!p)
            return false;
    }
    data = p->data;
    return true;
}

int list_count(data_node* list)
{
    int count = 0;
    data_node* p = list;
    while((p = p->link))
        count++;
    return count;
}

void list_print(data_node* list)
{
    data_node* p = list;
    while((p = p->link))
        cout<<p->data<<" ";
}

int find_last_k(data_node* list, int k)
{
    data_node* f, *p;
    p = list->link;
    f = list;
    int i;
    while(p)
    {
        p = p->link;
        i++;
        if(i >= k)
            f = f->link;
    }
    if (f != list)
        return f->data;
    return 0;
}

int main()
{
    data_node* list = new data_node;
    list->link = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        list_add(list,t);
    }
    list_print(list);
    cout<<"\nrst="<<find_last_k(list, 2);

    return 0;
}
