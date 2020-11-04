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

vector<pair<int, ll> >tree[200009];
int dis[200009], dis2[200009], vis[200009], vis_cnt, cs;

void Bfs2(ll src)
{
    queue<int>q;
    q.push(src);
    vis[src] = vis_cnt;
    while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto x: tree[u]){
                            if(vis[x.ff]!=vis_cnt){
                                      q.push(x.ff);
                                      dis2[x.ff]+=dis2[u]+x.ss;
                                      dis[x.ff] = max(dis[x.ff], dis2[x.ff]);
                                      vis[x.ff] = vis_cnt;
                            }
                }
    }

}

void Bfs(ll src)
{
    queue<int>q;
    q.push(src);
    vis[src] = vis_cnt;
    while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto x: tree[u]){
                            if(vis[x.ff]!=vis_cnt){
                                      q.push(x.ff);
                                      dis[x.ff]+=dis[u]+x.ss;
                                      vis[x.ff] = vis_cnt;
                            }
                }
    }

}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d;
    cin >> t;

    while(t--){
              scanf("%lld", &n);
              k = n;
              n--;
              for(int i=1; i<=k; i++){
                        tree[i].clear();
                        dis[i] = 0;
                        dis2[i] = 0;
              }
              while(n--){
                        ll u, v, w;
                        scanf("%lld %lld %lld", &u, &v, &w);
                        u++, v++;
                        tree[u].pb({v, w});
                        tree[v].pb({u, w});
              }
              vis_cnt++;
              Bfs(1);

              ll res = 0, res_d = 0;
              for(ll i=1; i<=k; i++){
                        if(res_d<dis[i]){
                                 res_d = dis[i];
                                 res = i;
                        }
              }
              memset(dis, 0, sizeof(dis));

              vis_cnt++;
              Bfs(res);

              res = 0, res_d = 0;

              for(ll i=1; i<=k; i++){
                        if(res_d<dis[i]){
                                 res_d = dis[i];
                                 res = i;
                        }
              }
              vis_cnt++;
              Bfs2(res);

              printf("Case %d:\n", ++cs);
              for(ll i=1; i<=k; i++){
                        printf("%d\n", dis[i]);
              }
    }
    return 0;
}
