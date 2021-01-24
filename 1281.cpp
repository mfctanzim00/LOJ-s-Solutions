#include<bits/stdc++.h>
#include<cstring>
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
const ll mod = 100000007;
const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};

struct Graph
{
    ll v, w, now;
};
vector<Graph>graph[mx];
ll dis[mx][15], src, dest, d, ret;
struct cmp
{
    bool operator()(Graph a, Graph b)
    {
        return a.w>b.w;
    }
};

void Dijkstra(ll n)
{
    priority_queue<Graph, vector<Graph>, cmp >pq;
    Graph edge;
    edge.v=edge.w=edge.now=0;
    pq.push(edge);
    dis[0][0]=0;

    while(!pq.empty()){
               ll cur_node=pq.top().v;
               ll cur_cost=pq.top().w;
               ll taken=pq.top().now;
               pq.pop();

               if(cur_node!=dest){
                       for(auto x: graph[cur_node]){
                                ll node=x.v;
                                ll cost=x.w;
                                ll type=x.now;
                                ll curr=type+taken;

                                if(curr>d)continue;
                                else{
                                       if(dis[cur_node][taken]+cost<dis[node][curr]){
                                                dis[node][curr]=dis[cur_node][taken]+cost;
                                                Graph edge;
                                                edge.v=node;
                                                edge.w=dis[node][curr];
                                                edge.now=curr;

                                                pq.push(edge);
                                       }
                                }
                       }
               }
               else break;
    }
    for(ll i=0; i<=d; i++){
            ret=min(ret, dis[n-1][i]);
    }

}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, cs=0;

    cin >> t;
    while(t--){
            ret=INT_MAX;
            cin >> n >> m >> k >> d;
            for(ll i=0; i<=n; i++){
                    for(ll j=0; j<=d; j++){
                            dis[i][j]=INT_MAX;
                    }
                    graph[i].clear();
            }
            src=0, dest=n-1;
            while(m--){
                     ll u, v, w;
                     cin >> u >> v >> w;
                     Graph edge;
                     edge.v=v;
                     edge.w=w;
                     edge.now=0;
                     graph[u].pb(edge);
            }
            while(k--){
                     ll u, v, w;
                     cin >> u >> v >> w;
                     Graph edge;
                     edge.v=v;
                     edge.w=w;
                     edge.now=1;
                     graph[u].pb(edge);
            }
            Dijkstra(n);
            cout << "Case " << ++cs << ": ";
            if(ret==INT_MAX)cout << "Impossible" << endl;
            else cout << ret << endl;
    }

    return 0;
}
