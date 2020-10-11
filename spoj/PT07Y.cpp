#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
bool visited[100001];
bool restack[100001];
list<int> li[10001];
bool DFS(int pos,int parent)
{
    visited[pos]=1;
    restack[pos]=1;
    list<int>::iterator it;
    for(it=li[pos].begin();it!=li[pos].end();++it)
    {
        if(!visited[*it])
        {
            if(DFS(*it,pos))
            return 1;
        }
        else if(*it!=parent && restack[*it])
        {
            return 1;
        }
    }
    restack[pos]=0;
    return 0;


}
int main()
{
    int N,E;
    cin>>N>>E;
    int t1,t2;
    
    for(int i=1;i<=N;i++)
    {
        li[i].clear();
        visited[i]=0;
        restack[i]=0;
    }
   
    for(int i=0;i<E;i++)
    {
        cin>>t1>>t2;
        li[t1].push_back(t2);
    }
     if(N==1 && E==0)
    {
         cout<<"YES"<<endl;
       return 0;
    }
    if(E!=N-1)
    {
        cout<<"NO"<<endl;
       return 0;
    }


    if(!DFS(1,-1))
    {
        bool connected=1;
        for(int i=1;i<=N;i++)
        {
            if(!visited[i])
            {
                connected=0;
                break;
            }
        }
        if(connected)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}