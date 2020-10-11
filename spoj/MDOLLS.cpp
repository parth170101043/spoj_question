#include<bits/stdc++.h>
#define ll long long  
using namespace std;

bool mysort(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
    return a.first<b.first;
}
int le[20000];
int main()
{
    
    int  t;
    cin>>t;
    vector<pair<int,int>> vec;
    int m,a,b;
    while(t--)
    {
        vec.clear();
        // memset(parent,-1,sizeof(parent));
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            vec.push_back({a,b});
            le[i-1]=1;
        }
       sort(vec.begin(),vec.end(),mysort);
       
    //    memset(subseq,1,sizeof(subseq));
       int maxi=1;
       for(int i=1;i<m;i++)
       {
           for(int j=i-1;j>=i;j--)
           {
               if(vec[j].second>=vec[i].second && le[i]<1+le[j])
               {
                   le[i]=1+le[j];
                   break;
               }
           }
           maxi=max(maxi,le[i]);
       }
        cout<<maxi<<endl;
    }
}