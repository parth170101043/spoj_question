#include<iostream>
#include<queue>

 #define ll long long  
using namespace std;
const ll P=1ll<<31-1;
bool matrix[1001][1001];
ll value[1001][1001];
int row[4]={1,0,-1,0};
int col[4]={0,1,0,-1};
int R;
// bool visited[1001][1001];
bool valid(int x,int y)
{
    if(x>=1 && x<=R && y>=1 && y<=R && matrix[x][y] && value[x][y]==-1)
    {
        return 1;
    }
    return 0;
}
ll DFS(int u,int v)
{
    if(u==R && v==R)
    return 1;
    if(value[u][v]!=-1)
    return value[u][v];
    ll ans=0;
    if(u+1<=R && matrix[u+1][v])
    {

        ans+=DFS(u+1,v)%P;
    }
    if(v+1<=R && matrix[u][v+1])
    ans=(ans+DFS(u,v+1)%P)%P;

    value[u][v]=ans;
    // visited[u][v]=1;
    return ans;
}


bool aslidfs(int u,int v)
{
    value[u][v]=0;

    for(int i=0;i<4;i++)
    {
        int x=u+row[i];
        int y=v+col[i];
        if(x==R and y==R )
        {
            return 1;
        }
        if(valid(x,y))
        {
            if(aslidfs(x,y))
            {
                return 1;
            }
        }
    }
    return false;
}
int main()
{
        cin>>R;
        
        char chr;
        int u,v,d1,d2;
       
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=R;j++)
            {
                 value[i][j]=-1;
                
                cin>>chr;
                
                if(chr=='.')
                {
                    matrix[i][j]=1;
                }
                else
                {
                    matrix[i][j]=0;
                }
                
            }
        }
        
        if(!matrix[1][1]||!matrix[R][R])
        {
            cout<<"INCONCEIVABLE"<<endl;
            return 0;
        }
        if(DFS(1,1)>0)
        {
            cout<<value[1][1]<<endl;
        }
        else
        {
            for(int i=1;i<=R;i++)
            for(int j=1;j<=R;j++)
            value[i][j]=-1;

            if(aslidfs(1,1))
            cout<<"THE GAME IS A LIE"<<endl;
            else
            {
            cout<<"INCONCEIVABLE"<<endl;
            }  
        }
}