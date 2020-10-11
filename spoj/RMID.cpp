#include<bits/stdc++.h>
 #include<cstdio>


#define ll long long  
using namespace std;
int main()
{
    list<int> l;
    list<int>::iterator it,temp,t1,t2;
    int n;
    it=l.begin();
    int count;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
        {
            printf("%d\n",(*it));
            temp=it;
            it++;
            t1=it;
            it--;
            if(it!=l.begin())
            it--;
            t2=it;
            if(count&1)
            {
                it=t2;
            }
            else
            {
                it=t1;
            }
            count--;
            l.erase(temp);  
        }
        else if(n==0)
        {
            count=0;
            l.clear();
            it=l.begin();
            cout<<endl;
        }
        else
        {
            l.push_back(n);
            count++;
            if(count&1)
            it++;

        }
        

    }
    return 0;
}
