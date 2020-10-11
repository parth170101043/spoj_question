#include<bits/stdc++.h>

#define ll long long  
using namespace std;
bool visited[100001];
vector<int> adj[100001];
// bool visited[10001]={0};
int id[100001];
int low[100001];
bool ar[100001]={0};
map<pair<ll,ll>,ll > bridges;
int timex=0;
ll dfs(int pos,int parent)
{
    int children=0;
    ll count=0;
    visited[pos]=1;
    timex+=1;
    id[pos]=timex;
    low[pos]=timex;
    // bool isart=0;
    vector<int>::iterator it;
    ll x=0;
    for(it=adj[pos].begin();it!=adj[pos].end();++it)
    { int v=*it;
        if(!visited[v])
        {
           
            children++;
            x=dfs(v,pos);
            count+=x;
            low[pos]=min(low[pos],low[v]);
            if(id[pos]<low[v])
              {
                  bridges.insert({{pos,v},x});
                //   cout<<"Here x =  "<<pos<<" , "<<v <<endl;
              }
            if(id[pos]<=low[v] && parent!=-1)
            {
              ar[pos]=1;
            }
            else if(parent==-1 && children>1)
            {
                ar[pos]=1;
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
    return count;
}
void dfs_bridge(ll pos,ll p,ll q,ll dst1,ll dst2,bool &d1,bool &d2)
{
    if(pos==p)
    {
        visited[pos]=1;
        vector<int>::iterator it;
        for(it=adj[pos].begin();it!=adj[pos].end();++it)
        { int v=*it;
            if(v==q)
            continue;
            if(v==dst1)
            {
                d1=1;
                
                if(d1 && d2)
                return ;
            }
            else if(v==dst2)
            {
                d2=1;
                if(d1 && d2)
                return ;
            }
            if(!visited[v])
            {   
               dfs_bridge(v,p,q,dst1,dst2,d1,d2);
                
            }
        }
    }
    else if(pos==q)
    {
        visited[pos]=1;
        vector<int>::iterator it;
        for(it=adj[pos].begin();it!=adj[pos].end();++it)
        { int v=*it;
            if(v==p)
            continue;
            if(v==dst1)
            {
                d1=1;
                
                if(d1 && d2)
                return ;
            }
            if(v==dst2)
            {
                d2=1;
                if(d1 && d2)
                return ;
            }
            if(!visited[v])
            {   
               dfs_bridge(v,p,q,dst1,dst2,d1,d2);
                
            }
        }
    }
    else
    {
        visited[pos]=1;
        vector<int>::iterator it;
        for(it=adj[pos].begin();it!=adj[pos].end();++it)
        { int v=*it;
            
            if(v==dst1)
            {
                d1=1;
                
                if(d1 && d2)
                return ;
            }
            if(v==dst2)
            {
                d2=1;
                if(d1 && d2)
                return ;
            }
            if(!visited[v])
            {   
               dfs_bridge(v,p,q,dst1,dst2,d1,d2);
                
            }
        }
    }
    
    // return 0;  
}

bool dfs_art(ll pos,ll C,ll dst)
{
    
        visited[pos]=1;
        vector<int>::iterator it;
        for(it=adj[pos].begin();it!=adj[pos].end();++it)
        { int v=*it;
            if(v==C)
            continue;
            if(v==dst)
            return 1;
            
            if(!visited[v])
            {   
                if(dfs_art(v,C,dst))
                {
                    return 1;
                }
            }
        }
    
    
    return 0;
   
}
void initialization(int N)
{
    // timex=0;
    for(int i=1;i<=N;i++)
    {
        visited[i]=0;
        // adj[i].clear();
    }
}
int main()
{
    ll N,E,B,C,D,Q;
    cin>>N>>E;
    int A;
    while(E--)
    {
        cin>>B>>C;
        adj[B].push_back(C);
        adj[C].push_back(B);
    }
    cin>>Q;
    dfs(1,-1);

    // set<pair<ll,ll>>::iterator it;
    // cout<<"Briges"<<endl;
    // for(it=bridges.begin();it!=bridges.end();++it)
    // {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    // cout<<"arts"<<endl;
    // for(int i=1;i<=N;i++)
    // {
    //     if(ar[i])
    //     {
    //         cout<<i<<" , ";
    //     }
    // }
    // cout<<endl;
    while (Q--)
    {
        // 
        cin>>A;
        if(A==1)
        {
            cin>>B>>C>>D>>E;
            if(B==C)
            {
                cout<<"da"<<endl;
                continue;
            }
            

            if(bridges.find({D,E})!=bridges.end())
            {
                initialization(N);
                bool d1 =0,d2=0;
                if(bridges[{D,E}]<N/2)
                {
                    dfs_bridge(E,E,D,B,C,d1,d2);
                    if(d1!=d2)
                    {
                        cout<<"ne"<<endl;
                    }
                    else
                    {
                        cout<<"da"<<endl;
                    }
                    
                }
                else
                {
                    dfs_bridge(D,D,E,B,C,d1,d2);
                    if(d1!=d2)
                    {
                        cout<<"ne"<<endl;
                    }
                    else
                    {
                        cout<<"da"<<endl;
                    }
                }
                
            }
            else if(bridges.find({E,D})!=bridges.end())
            {
                initialization(N);
                bool d1 =0,d2=0;
                if(bridges[{E,D}]<N/2)
                {
                    dfs_bridge(D,D,E,B,C,d1,d2);
                    if(d1!=d2)
                    {
                        cout<<"ne"<<endl;
                    }
                    else
                    {
                        cout<<"da"<<endl;
                    }
                    
                }
                else
                {
                    dfs_bridge(E,D,E,B,C,d1,d2);
                    if(d1!=d2)
                    {
                        cout<<"ne"<<endl;
                    }
                    else
                    {
                        cout<<"da"<<endl;
                    }
                }
            }
            else
            {
                 cout<<"da"<<endl;
            } 
        }
        if(A==2)
        {
            cin>>B>>C>>D;
            if(B==C)
            {
                cout<<"da"<<endl;
                continue;
            }
            if(B==D||C==D)
            {
                cout<<"ne"<<endl;
                continue;
            }
            if(ar[D])
            {
                initialization(N);

                if(dfs_art(B,D,C))
                {
                    cout<<"da"<<endl;
                }
                else
                {
                    cout<<"ne"<<endl;
                }
            }
            else
            {
                cout<<"da"<<endl;
            }
            
            
        }
    }
    

}

/*
13 15
1 2
2 3
3 5
2 4
4 6
2 6
1 4
1 7
7 8
7 9
7 10
8 11
8 12
9 12
12 13
5
1 5 13 1 2
1 6 2 1 4
1 13 6 7 8
2 13 6 7
2 13 6 8
*/