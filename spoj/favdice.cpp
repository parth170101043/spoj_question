#include <bits/stdc++.h>

using namespace std;

int main() {
	long long t,n;
    double ans;
	cin>>t;
    
	while(t--)
	{
        ans=0;
		cin>>n;
		int i=0;
        while(i<n)
        {
            ans+=(double)1/(n-i);
            i++;
        }
        ans*=n;
        cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	
}