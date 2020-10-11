#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
const ll P=1000000007;
list<int> li[10001];

void getpath(int &count,int pos,int des)
{
    if(pos==des)
    {
        count=(count+1)%P;
        return;
    }
    list<int>::iterator i;
    for(i=li[pos].begin();i!=li[pos].end();++i)
    {
        getpath(count,*i,des);
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int C,B,S,D;
        cin>>C>>B>>S>>D;
        for(int i=1;i<=C;i++)
        {
            li[i].clear();
        }
        int t1,t2;
        for(int i=0;i<B;i++)
        {
            cin>>t1>>t2;
            li[t1].push_back(t2);
        }
        int count=0;
        getpath(count,S,D);
        cout<<count<<endl;
    }
}