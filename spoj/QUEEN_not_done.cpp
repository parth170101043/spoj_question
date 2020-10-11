#include<iostream>
#include<queue>

// #define ll long long  
using namespace std;

bool visited[1001][1001];
int matrix[10001][1001];
int row[8]={1,0,-1,0,-1,1,-1,1};
int col[8]={0,1,0,-1,1,1,-1,-1};
int C,R;
bool issafe(int x,int y)
{
    
    if(x>=1 && x<=R && y>=1 && y<=C && matrix[x][y]>0)
    { 
        return 1;
    }
    return 0;   
}

int bfs(int u,int v,int d1,int d2)
{
   
   // visited[u][v]=1;
    queue<pair<int,int>> q;
    q.push({u,v});
     pair<int,int> pos;
    // map<pair<int,int>,int> mapa;
    // mapa.insert(make_pair(src,0));
    while(!q.empty())
    {
         pos=q.front();
         int posx=pos.first;
         int posy=pos.second;
            q.pop();
        // cout<<"pos = "<<pos.first<<" , "<<pos.second<<endl;
            int dis=matrix[posx][posy];
            //  cout<<posx<<" pos "<<posy<<endl;
            // bool valid=1;
            int k=1;
                for(int i=0;i<8;i++)
                {
                    k=1;
                    
                    while (1)
                    {
                         
                            int x=posx+k*row[i];
                            int y=posy+k*col[i];
                            if(x<1||y<1||x>R||y>C||matrix[x][y]==0)
                            break;
                            if(x==d1 && y==d2)
                                {
                                    // cout<<"pos"<<mapa[pos]<<",x= "<<pos.first<<",y = "<<pos.second<<endl;
                                    // cout<<posx<<" pos "<<posy<<endl;
                                    return dis+1;
                                }
                            
                            if(!visited[x][y])
                            {
                                // cout<<"POS "<<pos.first<<" , "<<pos.second<<" x ="<<x<<", y = "<<y<<"dis = "<<dis<<endl;

                                // nxt=make_pair(x,y);
                                
                                
                                q.push({x,y});
                                matrix[x][y]=dis+1;
                                visited[x][y]=1;   
                            }
                           
                            k++;
                        
                    }
               
             }
    }
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       
        cin>>R>>C;
        char chr;
        int u,v,d1,d2;
       
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
            {
                visited[i][j]=0;
                
                cin>>chr;

                
                if(chr=='.')
                {
                    matrix[i][j]=1;
                    continue;
                }
                else if(chr=='S')
                {
                    matrix[i][j]=0;
                    u=i;
                    v=j;
                    visited[u][v]=1;
                    continue;
                    // cout<<"src"<<i<<" "<<j<<endl;
                }
                else if(chr=='F')
                {
                    matrix[i][j]=1;
                    d1=i;
                    d2=j;
                    continue;
                    // cout<<"des"<<i<<" "<<j<<endl;
                }
                else
                {
                    matrix[i][j]=0;
                }
                
            }
        }
        cout<<bfs(u,v,d1,d2)<<endl;
        
    }
}



