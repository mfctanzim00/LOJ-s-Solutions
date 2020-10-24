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
const ll mx = 2e5+10;
const ll maxx = 1e17;
ll posx[] = {1,-1, 0, 0};
ll posy[] = {0, 0, 1,-1};

vector<pair<int, int> >graph[mx];
ll dis[mx];
priority_queue<pair<ll, ll> >pq;

void Dijkstra(int u)
{
    pq.push({0, u});
    dis[u] = 0;
    while(!pq.empty())
    {
        ll x = pq.top().second;
        ll y = pq.top().first*-1;
        pq.pop();
        if(y>dis[x])
            continue;
        for(auto i: graph[x])
        {
            ll cost = i.second;
            ll current_node = i.first;
            if(cost+dis[x]<dis[current_node])
            {
                dis[current_node] = cost+dis[x];
                pq.push({-1*dis[current_node], current_node});
            }
        }
    }
}

void init(int n)
{
    for(ll i=1; i<=n; i++)
    {
        dis[i] = maxx;
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

    int n, m, u, v, w, src, tar, t, cs=0;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        init(n);
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].pb({v, w});
            graph[v].pb({u, w});
        }
        Dijkstra(1);

        if(dis[n]!=maxx)
            printf("Case %d: %lld\n", ++cs, dis[n]);
        else
            printf("Case %d: Impossible\n", ++cs);
    }
    return 0;
}
