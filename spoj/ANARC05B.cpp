#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll getsum(vector<int> vec,int n,int m)
{
    ll sum=0;
    for(int i=n;i<=m;i++)
    {
        sum+=vec[i];
    }return sum;
}
int main()
{
    vector<ll> ansx;
    while(1)
    {
        int N,M;
        vector<int> arr1;
        vector<int> arr2;
        cin>>N;
        if(N==0)
        break;
        int temp;
        map<int,int> mapa;
        for(int i=0;i<N;i++)
        {
            cin>>temp;
            arr1.push_back(temp);
            mapa.insert(make_pair(temp,i));
        }
        cin>>M;
        for(int i=0;i<M;i++)
        {
            cin>>temp;
            arr2.push_back(temp);
        }
        
        ll arr1sum=0;
        ll arr2sum=0;
        int arr1lastpos=0;
        ll resultsum=0;
        int arr1pos=0;
        int sudo=0;

        for(int i=0;i<M;i++)
        {
            arr2sum+=arr2[i];
            if(mapa.find(arr2[i])!=mapa.end())
            {
                arr1sum=getsum(arr1,arr1lastpos,mapa[arr2[i]]);
                 if(arr1sum>arr2sum)
                        {
                            resultsum+=arr1sum;
                            //  cout<<" T POINT "<<arr2[i]<<"Add SUM "<<arr1sum<<endl;
                        }
                        else
                        {
                            resultsum+=arr2sum;
                            //  cout<<" T POINT "<<arr2[i]<<"Add SUM "<<arr2sum<<endl;
                        }
                arr2sum=0;
                arr1sum=0;
                arr1lastpos=mapa[arr2[i]]+1;
            }
        }

        if(arr1lastpos<N)
        {
            arr1sum=getsum(arr1,arr1lastpos,N-1);
             resultsum+=arr1sum>arr2sum?arr1sum:arr2sum;
                //  cout<<" T POINT X "<<arr1sum<<"arr2sum "<<arr2sum<<endl;
        }
        else
        {
            resultsum+=arr1sum>arr2sum?arr1sum:arr2sum;
            //cout<<" T POINT Y "<<arr1sum<<"arr2sum "<<arr2sum<<endl;
        }
        ansx.push_back(resultsum);

    }

    for(int i=0;i<ansx.size();i++)
    cout<<ansx[i]<<endl;

}
