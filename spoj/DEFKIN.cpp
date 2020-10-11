#include<bits/stdc++.h>  
#define ll long long  
using namespace std; 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w,h;
        cin >>w>>h>>n;
        if(n==0)
        {
            cout<<w*h<<endl;
            continue;
        }
        vector<int> wi(n);
        vector<int> hi(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>wi[i];
            cin>>hi[i];
        }
       
        sort(wi.begin(),wi.end());
        sort(hi.begin(),hi.end());
        int diffw=0;
        int diffh=0;
        // cout<<wi.size()<<"  "<<hi.size()<<" "<<endl;
        for(int i=1;i<n;i++)
        {
            diffh=max(diffh,hi[i]-hi[i-1]-1);
            diffw=max(diffw,wi[i]-wi[i-1]-1);

        }
        diffh=max(diffh,h-hi[n-1]);
        diffw=max(diffw,w-wi[n-1]);
        diffh=max(diffh,hi[0]-1);
        diffw=max(diffw,wi[0]-1);

        cout<<diffh*diffw<<endl;
    }
} 

/*
1
15 8 3
3 8
11 2
8 6
*/