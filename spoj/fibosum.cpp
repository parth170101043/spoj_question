#include <iostream>
#include<vector>
using namespace std;
#define fore(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll P=1000000007;
matrix mul(matrix A,matrix B,int k)
{
		matrix res(k,vector<ll>(k,0));

		fore(i,k)
		fore(j,k)
		fore(l,k)
		res[i][j]=(res[i][j]+(A[i][l]*B[l][j])%P)%P;
		return res;	
}

matrix power(matrix A,ll n,int k)
{
	if(n==1)
	return A;
	else if(n%2)
	{
		matrix x=power(A,n-1,k);
		return mul(A,x,k);
	}
	else
	{
		matrix x=power(A,n/2,k);
		return mul(x,x,k);
	}
}
matrix initialize(int k)
{
 matrix T(k,vector<ll>(k));
T[0][0]=0;
    T[0][1]=1;
    T[0][2]=0;
    T[1][0]=0;
    T[1][1]=0;
    T[1][2]=1;
    T[2][0]=-1;
    T[2][1]=0;
    T[2][2]=2;
    return T;
}


int main() {
	int t;
	int k=3;
	
	ll N;
	ll M;
    ll resN,resM,ansx;
	int b[3]={1,2,4};
   
    matrix MM;
    ll x;
    
   vector<ll> ans;
   cin>>t;
   matrix T;
   bool is_multiplied=0;
	while(t--)
	{
        T=initialize(k);
        is_multiplied=0;
        cin>>N;
        cin>>M;
        resN=0;
        resM=0;
        x=0;
		if(N==0||N==1)
        {
            resN=0;  
            x=M-3; 
        }
        else if(N==2)
        {
            resN=1;
            x=M-3;
        }
        else if(N==3)
        {
            resN=2;
            x=M-3;
        }
        else if(N==4)
        {
            resN=4;
            x=M-3;
        }
        else
        {
            is_multiplied=1;
            N--;
            MM=power(T,N-3,k);
            
            resN=0;
            fore(i,k)
		    {
			    resN=(resN+(MM[2][i]*b[i])%P)%P;
		    }
            x=M-N;
        }

        if(M==0)
        {
            resM=0;
        }
        else if(M==1)
        {
            resM=1;
        }
        else if(M==2)
        {
            resM=2;
        }
        else if(M==3)
        {
            resM=4;
        }
        else
        {
            T=power(T,x,k);
            if(is_multiplied)
            T=mul(T,MM,k);

            resM=0;
            fore(i,k)
		    {
			    resM=(resM+(T[2][i]*b[i])%P)%P;
		    }
        }
        ans.push_back(resM-resN);
	}
    int i=0;
    while (i<ans.size())
    {
       cout<<ans[i]<<endl;
       i++;
    }
    
}