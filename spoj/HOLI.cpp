#include <cstdio>
#include <iostream>
#include <vector>
 
using namespace std;
 
const int N = 100 * 1000 + 10;
 
vector<int> g[N], w[N];
bool u[N];
int cnt[N];
int n;
long long res;
 
void dfs(int v)
{
    u[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (u[to])
            continue;
        dfs(to);
        long long temp= min(cnt[to], n - cnt[to]) * 2ll * w[v][i];
        res+=temp;
        cout<<" res ,temp,w[v][i], v ,i , min(cnt[to], n - cnt[to])  "<<res<<", "<<temp<<", "<<w[v][i]<<", "<<v+1<<", "<<to+1<<", "<<min(cnt[to], n - cnt[to])<<endl;
        cnt[v] += cnt[to];
    }
}

void solve(int test)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        g[i].clear();
        w[i].clear();
        u[i] = false;
        cnt[i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    res = 0;
    dfs(0);
    printf("Case #%d: ", test);
    printf("%lld\n", res);
}
 
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
        solve(i);
 
    return 0;
}


/*
6
1 2 3
2 3 4
2 4 1
4 5 8
5 6 5
*/

/*
See no other place.
https://youtu.be/aZXi1unBdJA
*/