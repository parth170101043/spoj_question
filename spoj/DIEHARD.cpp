#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int Time=0;
        int H,A;
        cin>>H>>A;
        
        if(H<3 || (H<18 && A<9))
        {
            cout<<1<<endl;
            continue;
        }
        while(1)
        {
            if(Time%2==0)
            {
                H+=3;
                A+=2;
                Time++;
            }
            else
            {
                if(H<6 || (H<21 && A<11))
                {
                    break;
                }
                else if(H>=20 && A<19)
                {
                    H-=20;
                    A+=5;
                    Time++;
                    continue;
                }
                else if(H>5 && A>10 )
                {
                   H-=5;
                   A-=10;
                   Time++;
                }
                
                

            }
            
        }
        cout<<Time<<endl;
    }
}