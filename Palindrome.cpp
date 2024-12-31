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
void print_normal(Node *head) 
{
    Node *tmp = head; 
    while (tmp != NULL)  
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
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
void print_reverse(Node *tail)
{
    Node *tmp = tail;
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
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        insert_tail(head, tail, n);
    }
    Node *tmp = head;
    Node *tmp2 = tail;
    bool flag = true;
    while (tmp != NULL && tmp2 != NULL)
    {
        if (tmp->val != tmp2->val)
        {
            flag = false;
            break;
        }
        tmp = tmp->next;
        tmp2 = tmp2->prev;
    }
    if (flag==true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
