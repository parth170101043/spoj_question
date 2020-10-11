#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

bool mysort(ll a,ll b)
{
    return a<=b?1:0;
}
bool ispossible(long int M,long int N,vector<ll> arr,ll saw)
{
   
    int cow=1;
   
    ll currpos=0;
    for(int i=1;i<N;i++)
    {
        if((arr[i]-arr[currpos])<saw)
        {
            
        }
        else
        {   
            currpos=i;
            cow++;
            if(cow>=M)
            return 1;
        }
        
    }
    return 0;
}

int main()
{
   
   long int n;
     ll maxi=INT_MIN;
     ll start=0,ends,mid;
   long int c;
   long int t;
   cin>>t;
   while(t--)
   {
    cin>>n;
     vector<ll> arr;
     arr.clear();
     cin>>c;
     ll sum=0;
     ll temp;
    for(long int i=0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
        if(temp>maxi)
        maxi=temp;
    }
    sort(arr.begin(),arr.end(),mysort);
    ends=maxi;
    start=0;
   
    mid=start+(ends-start)/2;
    
    ll ans=0;
    while(start<=ends)
    {
       
        if(ispossible(c,n,arr,mid))
        {
           
            ans=mid;
            start=mid+1;
        }
        else
        {
            ends=mid-1;
        }
         mid=start+(ends-start)/2;
        
    }
cout<<ans<<endl;
   }

}