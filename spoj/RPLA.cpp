#include<bits/stdc++.h>

 #define ll long long  
using namespace std;
vector<int> adj[1000];
int indegree[1000];
vector<pair<int,int>> ans;

bool mysort(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
   return a.second<b.second;
}
int main()
{
    int T,N,R;//N=no  of nodes...//R no of edges...
    cin>>T;
    for(int h=0;h<T;h++)
    {
         ans.clear();
        cout<<"Scenario #"<<h+1<<":"<<endl;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            adj[i].clear();
            indegree[i]=0;
        }
        cin>>R;
        int v,u;
        while(R--)
        {
            cin>>v>>u;
            adj[u].push_back(v);
        }
        int x,rank;
        
        for(int u=0;u<N;u++)
        {
            vector<int>::iterator it;
            for(it=adj[u].begin();it!=adj[u].end();++it)
            {
                indegree[*it]++;
            }
        }
        
        queue<pair<int,int>> q;
       
        // int cnt=0;
        // int rank=1;
        for(int i=0;i<N;i++)
        if(indegree[i]==0)
        q.push({i,1});
       
        while (!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            int u=temp.first;
            int rank=temp.second;
            ans.push_back(temp);
             vector<int>::iterator it;
             for(it=adj[u].begin();it!=adj[u].end();++it)
             {
                 if(--indegree[*it]==0)
                 q.push({*it,rank+1});
             }
            //  cnt++;
        }
        // if(cnt!=v)
        sort(ans.begin(),ans.end(),mysort);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].second<<" "<<ans[i].first<<endl;
        }
    }
}


/*
2



5 6

2 0

2 4

1 4

1 2

3 2

4 0

 

5 4

1 0

2 0

3 2

4 2
*/