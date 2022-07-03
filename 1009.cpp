#include<bits/stdc++.h>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl
const int mx = 1e5+7;
using ll=long long;

vector<int>graph[mx];
int cur, vis[mx], col, tot;

void Dfs(int src, bool isVampire)
{
    vis[src]=col;
    cur+=isVampire;
    tot++;
    for(auto child: graph[src]){
           if(vis[child] != col){
                 Dfs(child, isVampire^1);
           }
    }
}

int main()
{
    int t=1, n, m, k;
    scanf("%d", &t);

    int cs=0;
    while(t--){
            scanf("%d", &n);
            for(int i=1; i<=n; i++){
                   int u, v;
                   scanf("%d %d", &u, &v);
                   graph[u].push_back(v);
                   graph[v].push_back(u);
            }
            int ans=0; ++cs; ++col;
            for(int i=1; i<=20000; i++){
                   if(graph[i].size()==0)continue;
                   if(vis[i] != col) {
                          cur = tot = 0;
                          Dfs(i, 0);
                          ans += max(cur, tot-cur);
                   }
            }
            printf("Case %d: %d\n", cs, ans);
            for(int i=1; i<=20000; i++)graph[i].clear();
    }
    return 0;
}
