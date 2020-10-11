#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>


using namespace std;
typedef long long ll;
void topsort(ll pos,bool visited[],stack<ll> &st, vector<ll> s[])
{
    visited[pos]=1;
    vector<ll>::iterator it;
    for(it=s[pos].begin();it!=s[pos].end();++it)
    {
        if(!visited[*it])
        {
            topsort(*it,visited,st,s);
        }
    }
    st.push(pos);
}

void topsort1(ll pos,bool visited[],vector<ll> &ans, vector<ll> s[])
{
    visited[pos]=1;
    cout<<"topsort1 = "<<pos<<endl;
    vector<ll>::iterator it;
    for(it=s[pos].begin();it!=s[pos].end();++it)
    {
        if(!visited[*it])
        {
            topsort1(*it,visited,ans,s);
        }
    }
    ans.push_back(pos);
}

int main()
{
    ll N,M;
    cin>>N>>M;
    vector<ll> s[N+1];
    vector<ll> alt[N+1];
    ll u,v;
    bool visited[N+1]={0};
    for(ll i=1;i<=N;i++)
    visited[i]=0;

    while(M--)
    {
        cin>>u>>v;
        s[u].push_back(v);
        alt[v].push_back(u);
    }
    stack<ll> st;
    for(ll i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            topsort(i,visited,st,s);
        }
    }
    vector<ll> ans;

    for(ll i=1;i<=N;i++)
    visited[i]=0;

    ll pp;
    bool doneone=0;
    map<ll,int> final;
    while(!st.empty())
    {
        pp=st.top();
        st.pop();
        cout<<"stackvalue = "<<pp<<endl;
        if(!visited[pp])
        {
            ans.clear();
            topsort1(pp,visited,ans,alt);
            cout<<ans.size()<<"  =  size  "<<endl;
            if(!doneone)
            {
                
                for(ll i=0;i<ans.size();i++)
                {
                    cout<<ans[i]<<" , ";
                    // cout<<" ans "<<ans[i]<<endl;
                    final.insert({ans[i],1});
                }
                doneone=1;
            }
            else
            {
                for(ll i=0;i<ans.size();i++)
                {
                    cout<<ans[i]<<" , ";
                    if(final.find(ans[i])!=final.end())
                    {
                        // cout<<" ans "<<ans[i]<<endl;
                        final[ans[i]]++;
                    }
                }
            }
            cout<<endl;
            // ans.clear();
        }
    }
    map<ll,int>::iterator it;
    int ct=0;
    for(it=final.begin();it!=final.end();++it)
    {   
       int f=it->first;
       int jk=it->second;
       cout<<" first "<<f<<" , second "<<jk<<endl;
        if(it->second>=N-1)
        {
           ct++;
        }
    }
    cout<<ct<<" = count"<<endl;
    for(it=final.begin();it!=final.end();++it)
    {
        if(it->second>=N-1)
        {
          cout<<it->first<<" ";
        }
    }
}

/*
4 4

1 2

3 2

4 3

2 1
*/