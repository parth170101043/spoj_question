#include<bits/stdc++.h>

#define ll long long  
using namespace std;
bool visited[10001];
int id[10001];
int low[10001];
vector<int> adj[10001];
int timex=0;
void dfs(int pos,int parent,int &ar)
{
    
    int children=0;

    visited[pos]=1;
    timex+=1;
    id[pos]=timex;
    low[pos]=timex;
    bool isart=0;
    vector<int>::iterator it;
    for(it=adj[pos].begin();it!=adj[pos].end();++it)
    { int v=*it;
        if(!visited[v])
        {
           
            children++;
            dfs(v,pos,ar);
            
            low[pos]=min(low[pos],low[v]);
            if(id[pos]<=low[v] && parent!=-1)
            {
               isart=1;
            }
            else if(parent==-1 && children>1)
            {
                isart=1;
            }
        }
        else
        {
            if(v!=parent)
            {
                low[pos]=min(id[v],low[pos]);
            }
        } 
    }
    if(isart)
    ar++;
}
void initialization(int N)
{
    timex=0;
    for(int i=1;i<=N;i++)
    {
        visited[i]=0;
        adj[i].clear();
    }
}
int main()
{
    int N;
    ll M;
    while(1)
    {
        cin>>N>>M;
        if(N==M && M==0)
        return 0;
        int u,v;
        initialization(N);
        while (M--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ar=0;
        // cout<<"TILL here"<<endl;
        // timex=0;
        dfs(1,-1,ar);
        
        cout<<ar<<endl;
    }
}

/*
3 3
1 2
2 3
1 3
*/
/*
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
*/
/*
3 3
1 2
2 3
1 3
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
0 0
*/