#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
bool ispossible(ll M,int N,int arr[],ll saw)
{
    //yha dekho agar machine ka length saw hua toh tunhara requirement satisfy hota ki nhi
   
    ll count=0;
    for(int i=0;i<N;i++)
    {
        if((arr[i]-saw)>0)
        {count+=(arr[i]-saw);
       
        if(count>=M)
        return 1;
        }
    }
    return 0;
}
int main()
{
    //krna ye hai ki machine(hack saw ) ka length jitna ho sake jyada ho aur (tumhara requirement v satisfy ho)
    //machine ka jyada lenth mtlb lakri kam katega
    int n;
     int maxi=INT_MIN;
     ll start=0,ends,mid;
   ll m;
    cin>>n;
     int arr[n];
     cin>>m;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>maxi)
        maxi=arr[i];
    }
    ends=maxi;
   //maxi mtlb sbse lmba tree length...toh tum apne hacksaw ka maximum length maxi-1 le skte ho....isse jyad lia toh ghnta koi faida nhi hoga=tree v nhi ktega
   //ab lgao binary search 
    mid=start+(ends-start)/2;
    //mid hoga tumhara machine length
    ll ans=0;
    while(start<=ends)
    {
       
        if(ispossible(m,n,arr,mid))
        {
            /*requirement satisfy hua toh result ko save kro aur saw length ko aur jyada krke dekho....kyuki (krna ye hai ki machine(hack saw ) ka length jitna ho sake jyada ho aur m(tumhara requirement v satisfy ho)*/
            ans=mid;
            start=mid+1;
        }
        else
        {
            /*requirement satisfy nhi hua toh length kam krke dekho*/
            ends=mid-1;
        }
         mid=start+(ends-start)/2;
        
    }
cout<<ans<<endl;

}