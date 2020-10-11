#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
unordered_set<int> li[10001];
bool visited[10001];
void DFS(int pos,int oldl,int& max_len,int &best)
{
    visited[pos]=1;
    // int cur_len=0;
     
        unordered_set<int>::iterator it;
        for(it=li[pos].begin();it!=li[pos].end();++it)
        {
            int v=*it;
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
    int N;
    cin>>N;
    int temp,temp1;
    int max_len=0;
    int best=0;
    for(int i=1;i<N;i++)
    {
        cin>>temp>>temp1;
        li[temp].insert(temp1);
        li[temp1].insert(temp);
    }
        for(int j=1;j<=N;j++)
        visited[j]=0;
        DFS(1,0,max_len,best);
        max_len=0;
        for(int j=1;j<=N;j++)
        visited[j]=0;
        DFS(best,0,max_len,temp);
    
    cout<<max_len;
}