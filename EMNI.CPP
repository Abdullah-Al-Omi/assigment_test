#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> save_list;
    while(true)
    {
        int n;
        cin>>n;
        if(n==-1)
        {
            break;
        }
        save_list.push_back(n);
    }
    for(auto i=save_list.begin();i!=save_list.end();i++)
    {
        cout<<*i<<" ";
    }
    cout << endl;

return 0;
}