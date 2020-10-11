#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
bool mysort(ll a,ll b)
{
    return a>b;
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        ll N;
        cin>>N;
        vector<ll> vec(N);
        ll ones=0;
        for(ll i=0;i<N;i++)
        {
            cin>>vec[i];
            if(vec[i]==1)
            ones++;

        }
        sort(vec.begin(),vec.end(),mysort);
        if(N==2 && vec[0]==3 and vec[1]==2)
        {

        cout<<2<<" "<<3<<" "<<endl;
        continue;
        }
        
        for(int i=0;i<ones;i++)
        {
            cout<<1<<" ";
        }
       
        {
            for(int i=0;i<N-ones;i++)
            cout<<vec[i]<<" ";
        }
        
        cout<<endl;
    }
}