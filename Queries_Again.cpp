#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next; 
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL; 
        this->prev = NULL; 
    }
};
void insert_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL) 
    {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode; 
    newNode->next = head; 
    head = head->prev; 
}
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL) 
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;   

    newNode->prev = tail; 
    tail = tail->next; 
}

int size(Node *head)
{
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL) 
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
void insert_at(Node *&head, Node *&tail, int pos, int val)
{
    if (pos == 0) 
    {
        insert_head(head, tail, val);
        return;
    }
    if (pos == size(head)) 
    {
        insert_tail(head, tail, val);
        return;
    }
    Node *tmp = head;
    for (int i = 0; i < pos - 1; i++) 
    {
        tmp = tmp->next;
    }
    Node *newNode = new Node(val);
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}
void print_normal(Node *head) 
{
    Node *tmp = head; 
    cout<<"L -> ";
    while (tmp != NULL)  
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void print_reverse(Node *tail)
{
    Node *tmp = tail;
    cout<<"R -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL; 
    Node *tail = head; 
    int n;
    cin>>n;
    while(n--)
    {
        int x, y;
        cin>>x>>y;
      
            if (x==0)
            {
                insert_head(head, tail, y);
                print_normal(head);
                print_reverse(tail);
            }
            else if (x==size(head))
            {
            insert_tail(head, tail, y);
            print_normal(head);
            print_reverse(tail);
            }
            else if (x<size(head))
            {
                insert_at(head, tail, x, y);
                print_normal(head);
                print_reverse(tail);}
        else {
            cout<<"Invalid"<<endl;
             }
    }
       
    
}
