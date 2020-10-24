#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define ll long long
#define ull unsigned long long
#define pb push_back
#define ff first
#define ss second
#define all(v) (v.begin(), v.end())
#define pi acos(-1.0)
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define bug(a) cerr << #a << " : " << a << endl
#define pq dp
using namespace std;
const ll mx = 2e5;

ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

vector<pair<ll, ll> >graph[mx];
ll vis[mx], dis[mx], cnt;

void Bfs(ll src)
{
    queue<ll>q;
    q.push(src);
    vis[src] = ++cnt;
    while(!q.empty()){
                ll u = q.front();
                q.pop();
                for(auto x: graph[u]){
                            if(vis[x.ff]!=cnt){
                                      q.push(x.ff);
                                      dis[x.ff]=dis[u]+x.ss;
                                      vis[x.ff] = cnt;
                            }
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

    ll t=1, n, k, m, a, b, c, d;
    cin >> t;

    for(int tc=1; tc<=t; tc++){
             cin >> n;
             k = n;
             n--;
             while(n--){
                       ll u, v, w;
                       cin >> u >> v >> w;
                       graph[u].pb({v, w});
                       graph[v].pb({u, w});
             }
             n = k;
             Bfs(0);

             ll res = 0, res_d = 0;
             for(ll i=0; i<n; i++){
                       if(res_d<dis[i]){
                                res_d = dis[i];
                                res = i;
                       }
             }
             for(int i=0; i<n; i++){
                       dis[i] = 0;
             }

             Bfs(res);

             res = 0;
             for(ll i=0; i<n; i++){
                       if(res<dis[i]){
                                res = dis[i];
                       }
             }
             cout << "Case " << tc << ": " << res << endl;

             for(int i=0; i<n; i++){
                       dis[i] = 0;
                       graph[i].clear();
             }
    }

    return 0;
}
