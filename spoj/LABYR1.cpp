#include<bits/stdc++.h>  
#define ll long long  
using namespace std;
bool visited[1001][1001];
bool matrix[10001][1001];
int row[4]={1,0,-1,0};
int col[4]={0,1,0,-1};
int C,R;
void DFS(pair<int,int> pos,pair<int,int> &best,ll oldl,ll& maxl)
{
    int u=pos.first;
    int v=pos.second;
    visited[u][v]=1;
    for(int i=0;i<4;i++)
    {
        int x=u+row[i];
        int y=v+col[i];
        if(matrix[x][y] && !visited[x][y])
        {
            if(maxl<oldl+1)
            {
                maxl=oldl+1;
                best=make_pair(x,y);
            }
            DFS(make_pair(x,y),best,oldl+1,maxl);
        }
    }
    
}

int main()
{
    ll T;
    cin>>T;
    while(T--)
    {
       
        cin>>C>>R;
        char chr;
      
       
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
            {
                visited[i][j]=0;
                cin>>chr;
                if(chr=='#')
                {
                    matrix[i][j]=0;
                }
                else
                {
                    matrix[i][j]=1;
                }  
            }
        }

        ll final_len=0;

        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
            {
                if(matrix[i][j] &&!visited[i][j])
                {
                 pair<int,int> best;
                 ll max_len=0;
                 DFS(make_pair(i,j),best,0,max_len);
                 if(max_len>0)
                 {
                     max_len=0;
                    pair<int,int> temp=best;
                    for(int p=1;p<=R;p++)
                    {
                        for(int q=1;q<=C;q++)
                        visited[p][q]=0;
                    }
                    DFS(temp,best,0,max_len);
                    if(max_len>final_len)
                    {
                        final_len=max_len;
                    }
                 }
                 
                }
            }
        }
       cout<<"Maximum rope length is "<<final_len<<"."<<endl;
    }
}
