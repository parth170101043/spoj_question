#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll maxt(int n,int r)
{
    ll time=0;
   
    int i=1;
    while(n--)
    {
        time+=i*r;
        i++;
    }
    return time;
}
bool ispossible(vector<int> arr,ll time,int x,int size)
{
    int count=0;
    ll xtime=0;
    
    for(int i=0;i<size;i++)
    {
        int r=arr[i];
        int j=1;
        xtime=0;
       
        while(xtime+j*r<=time)
        {
            count++;
            xtime+=j*r;
            if(count>=x)
            return 1;
            j++;
        }

    }return 0;

}
int main()
{
    int t,n,l,temp;
    ll mini,maxi,start,end,mid;
     vector<int> rank;
    cin>>t;
    vector<ll> ansx;
    while(t--)
    {
        mini=INT_MAX;
        maxi=INT_MIN;
        cin>>n;
        cin>>l;
        rank.clear();
        for(int i=0;i<l;i++)
        {
            cin>>temp;
            rank.push_back(temp);
            if(temp>maxi)
            maxi=temp;
            
        }
       if(l==1)
       {
           ansx.push_back(maxt(n,maxi));
       }
       else
       {
           start=0;
           end=maxt(n,maxi);
           mid=start+(end-start)/2;
           ll ans=end;
        //    cout<<ans<<"ans"<<endl;
           while(start<=end)
           {
               if(ispossible(rank,mid,n,l))
               {
                   end=mid-1;
                   ans=mid;
                //    cout<<ans<<"ans"<<endl;
               }
               else
               {
                   start=mid+1;
               }
               mid=start+(end-start)/2;
           }
          ansx.push_back(ans);
       }


    }
    for(int x=0;x<ansx.size();x++)
    cout<<ansx[x]<<endl;
}