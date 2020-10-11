#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
int main()
{  while(1)
    {       ll N;ll cost=0,need=0;
        cin>>N;
        if(N==0)
        return 0;
        ll temp;
        for(int i=0;i<N;i++)
        { cin>>temp;
            need+=temp;
            cost+=abs(need); }
        cout<<cost<<endl;}
}
