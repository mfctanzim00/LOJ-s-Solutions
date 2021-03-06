#include<bits/stdc++.h>
#include<cstring>
//#define Mfc_Tanzim
#define  ll        long long
#define  ull       unsigned long long
#define  pb        push_back
#define  ff        first
#define  ss        second
#define  all(v)    (v.begin(), v.end())
#define  pi        acos(-1.0)
#define  FastRead  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define  bug(a)    cerr << #a << " : " << a << endl
using namespace std;
const ll mx = 1000;
const ll maxx = 1e17;
ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

vector<pair<ll, ll> >graph[mx];
ll dis[mx];
priority_queue<pair<ll, ll> >pq;

void Dijkstra(ll u)
{
    pq.push({0, u});
    dis[u] = 0;
    while(!pq.empty()){
            ll x = pq.top().second;
            ll y = pq.top().first;
            pq.pop();
            for(auto i: graph[x]){
                      ll cost = max(i.second, y);
                      ll current_node = i.first;
                      if(cost<dis[current_node]){
                                   dis[current_node] = cost;
                                   pq.push({dis[current_node], current_node});
                      }
            }
    }
}

void init(ll n)
{
    for(ll i=0; i<n; i++){
            dis[i] = maxx;
            if(graph[i].size())
                    graph[i].clear();
    }
}

int main()
{
    //FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif // Mfc_Tanzim

    ll n, m, u, v, w, src, tar, t;

    scanf("%lld", &t);

    for(ll tc=1; tc<=t; tc++){
             printf("Case %lld:\n", tc);
             scanf("%lld %lld", &n, &m);
             init(n);
             while(m--){
                      scanf("%lld %lld %lld", &u, &v, &w);
                      graph[u].pb({v, w});
                      graph[v].pb({u, w});
             }
             scanf("%lld", &src);
             Dijkstra(src);

             for(int i=0; i<n; i++){
                      if(dis[i]!=maxx)
                              printf("%lld\n", dis[i]);
                      else
                              printf("Impossible\n");
             }
    }

    return 0;
}
