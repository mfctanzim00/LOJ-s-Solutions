#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;
const ll mod = 1e9+7;
const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};
ll cs, vis[1000], tmp, value[1000][1000];
vector<int>graph[1000];

void Dfs(int src)
{
    vis[src] = true;
    for(auto x: graph[src]){
             if(!vis[x]){
                      if(value[src][x]==0)
                           tmp+=value[x][src];
                      Dfs(x);
             }
    }
}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n;
    cin >> t;

    while(t--){
            cin >> n;
            ll left_node = -1, right_node = -1;
            for(int i=1; i<=n; i++){
                    graph[i].clear();
                    for(int j=1; j<=n; j++){
                            value[i][j] = 0;
                    }
            }

            for(int i=1,u,v,w; i<=n; i++){
                     cin >> u >> v >> w;
                     graph[u].pb(v);
                     graph[v].pb(u);
                     value[u][v] = w;
                     if(u==1){
                             if(left_node==-1){
                                      left_node = v;
                             }
                             else  right_node = v;
                     }
                     else if(v==1){
                             if(left_node==-1){
                                      left_node = u;
                             }
                             else  right_node = u;
                     }
            }

            ///Traversing to the left side of Node 1
            ll ret = INT_MAX;
            tmp = 0;
            for(int i=1; i<=n; i++) vis[i] = 0;
            vis[1] = true;
            Dfs(left_node);
            if(value[1][left_node]==0)
                   tmp+=value[left_node][1];
            if(value[right_node][1]==0)
                   tmp+=value[1][right_node];
            ret = min(ret, tmp);

            ///Traversing to the Right side of Node 1
            for(int i=1; i<=n; i++) vis[i] = 0;
            vis[1] = true;
            tmp = 0;
            Dfs(right_node);
            if(value[1][right_node]==0)
                   tmp+=value[right_node][1];
            if(value[left_node][1]==0)
                   tmp+=value[1][left_node];
            ret = min(ret, tmp);

            cout << "Case " << ++cs << ": " << ret << "\n";
    }
    return 0;
}
