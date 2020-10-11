#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
unordered_set<int> li[2002];
bool visited[2002];
bool dfs(int &count,int pos,int parent)
{
    count++;
    // cout<<pos<<endl;
    visited[pos]=1;
    unordered_set<int>::iterator it;
    for(it=li[pos].begin();it!=li[pos].end();++it)
    {
        int v=*it;
        if(!visited[v])
        {
            if(dfs(count,v,pos))
            {
                return 1;
            }
        }
        else if(v!=parent)
        {
            //remember cycle size>2 always
           return 1;
            
        }
    }
    // cout<<"pos = "<<pos<<", countxx = "<<count<<endl;
    count--;
    return 0;
}
int main()
{
    int T;
    cin>>T;
   for(int j=1;j<=T;j++)
    {
        int N;
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            li[i].clear();
            visited[i]=0;
        }
        ll interatcion;
        cin>>interatcion;
        int temp,temp1;
        bool found=0;
        for(ll i=0;i<interatcion;i++)
        {
            cin>>temp>>temp1;
            li[temp1].insert(temp);
            li[temp].insert(temp1);
            if(temp==temp1)
            found=1;
        }
        int count=0;
        
        if(found)
        {
            cout<<"Scenario #"<<j<<":"<<endl;
                cout<<"Suspicious bugs found!"<<endl;
                continue;
        }
        for(int i=1;i<=N;i++)
        {count=0;
            if(!visited[i])
            if(dfs(count,i,-1) && count%2)
            {
                found=1;
                cout<<"Scenario #"<<j<<":"<<endl;
                cout<<"Suspicious bugs found!"<<endl;
                break;
            }

        }
        
        if(!found)
        {
            cout<<"Scenario #"<<j<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }

    }
}

/*
1        
6 6
1 2
2 3
3 4
4 5
5 6
1 6
*/