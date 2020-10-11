#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
unordered_set<int> li[100001];
bool visited[100001];
void DFS(ll pos,ll oldl,ll& max_len,ll &best)
{
    visited[pos]=1;
    // int cur_len=0;
     
        unordered_set<int>::iterator it;
        for(it=li[pos].begin();it!=li[pos].end();++it)
        {
            ll v=*it;
            if(!visited[v])
            {
                if(oldl+1>max_len)
                {
                    max_len=oldl+1;
                    best=v;
                }
                
                DFS(v,oldl+1,max_len,best);
            }

        }
    
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll N;
        cin>>N;
        ll temp,temp1;
        ll max_len=0;
        ll best=0;
        for(int i=0;i<N;i++)
        li[i].clear();

        for(ll i=0;i<N-1;i++)
        {
            cin>>temp>>temp1;
            li[temp].insert(temp1);
            li[temp1].insert(temp);
        }
            for(ll j=0;j<N;j++)
            visited[j]=0;
            DFS(0,0,max_len,best);
            max_len=0;
            for(ll j=0;j<N;j++)
            visited[j]=0;
            temp=0;
            temp1=0;
            temp=best;
            DFS(temp,0,max_len,temp1);
        
        //if(max_len%2)
        cout<<(max_len+1)/2<<endl;
        
        
    }
    
}