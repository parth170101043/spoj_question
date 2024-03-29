#include<bits/stdc++.h>

 #define ll long long  
using namespace std;
struct Point 
{ 
    int x; 
    int y; 
}; 
int parent[1001];

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 
  
// Driver program to tes

void initialize(int N)
{
    for(int i=1;i<=N;i++)
    parent[i]=-1;
}
int find(int x)
{
    if(parent[x]<0)
    return x;
    return parent[x]=find(parent[x]);
}
void unionx(int x,int y)
{
    if(parent[x]<parent[y])
    {
        parent[x]+=parent[y];
        parent[y]=x;
    }
    else
    {
        parent[y]+=parent[x];
        parent[x]=y;
    }
}
int main()
{
    int t,n,m,x1,y1,x2,y2;
    Point p1,p2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        map<int,pair<Point,Point>> mapa;
        for(int i=0;i<n;i++)
        {
            cin>>p1.x>>p1.y>>p2.x>>p2.y;
            // cout<<p1.x<<p1.y<<p2.x<<p2.y;
            mapa[i+1]={p1,p2};
        }
        initialize(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int x=find(i);
                int y=find(j);
                if(x!=y)
                {
                    if(doIntersect(mapa[i].first,mapa[i].second,mapa[j].first,mapa[j].second))
                    {
                        unionx(x,y);
                    }
                }
            }
        }

        while(m--)
        {
            cin>>x1>>x2;
            if(find(x1)==find(x2))
            cout<<"YES"<<endl;
            else
            {
                cout<<"NO"<<endl;
            }
            
        }
    }
}