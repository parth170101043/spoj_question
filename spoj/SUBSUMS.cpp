#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const long int MAX=1<<18;
ll X[MAX],Y[MAX];
ll getsum(vector<ll> vec,ll num,int N,int start)
{
    ll sum=0;
    for(int i=0;i<N;i++)
    {
        if(num&(1<<i))
            sum+=vec[i+start];
    }
    return sum;
}
void calcsubarray(vector<ll> a,ll x[],int n,int start)
{

    for(int i=0;i<(1<<n);i++)
    {
        x[i]=getsum(a,i,n,start);
    }
}
int main()
{
    ll A,B;
    int N;
    cin>>N;
    
    vector<ll> vec;
    cin>>A>>B;
    
    ll temp;
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    int size_x=1<<(N/2);
    int size_Y=1<<(N-N/2);
    
    calcsubarray(vec,X,N/2,0);
    calcsubarray(vec,Y,N-N/2,N/2);
    sort(Y,Y+size_Y);

    // for(int i=0;i<size_x;i++)
    // cout<<X[i]<<" ";
    // cout<<endl;

    // for(int i=0;i<size_Y;i++)
    // cout<<Y[i]<<" ";
    // cout<<endl;

    

    int count=0;
    ll sudo=0;
    for(int i=0;i<size_x;i++)
    {
        if(X[i]<A)
        {
            int P=lower_bound(Y,Y+size_Y,A-X[i])-Y;
            if (P == size_Y || X[i]+Y[P]>B)
                continue;
                int Q=lower_bound(Y,Y+size_Y,B-X[i])-Y;
                if(Q==size_Y)
                Q--;
                while(X[i]+Y[Q+1]<=B  && (Q+1)<size_Y)
                Q++;
                while(X[i]+Y[Q]>B)
               {
                   Q--;
            
               }
                count+=(Q-P)+1;
        }
        else if(X[i]>=A && X[i]<=B)
        {
            //int P;
            int R=0;
            // cout<<"X[i] "<<X[i]<<endl;
                if(Y[0]<0)
                {
                  int  P=lower_bound(Y,Y+size_Y,A-X[i])-Y;

                    R=lower_bound(Y,Y+size_Y,0)-Y;

                    count+=(R-P);
                    // cout<<" R "<<R<<" P "<<P<<endl;
                }
                if(Y[R+1]+X[i]>B)
                continue;
                int Q=lower_bound(Y,Y+size_Y,B-X[i])-Y;
                while(X[i]+Y[Q+1]<=B && (Q+1)<size_Y)
                Q++;
                while(Y[Q]+X[i]>B)
                Q--;
               count+=(Q-R)+1;
            //    cout<<" Q "<<Q<<endl;
            
        }
    }

cout<<count<<endl;
}
/*
3 -1 2
1
-2
3
*/


/*5 6 12
2
1
5
6
4*/