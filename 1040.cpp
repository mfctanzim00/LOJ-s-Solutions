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
const ll maxn = 100;

struct edge
{
    int u,v,w;
};

vector<edge>graph,output;
ll parent[maxn], mstValue, cnt;

bool compare(edge a, edge b)
{
    return a.w<b.w;
}

int Find(ll r)
{
    if(parent[r]==r)
        return r;
    return parent[r]=Find(parent[r]);
}

void initPar(ll r)
{
    for(ll i=0 ; i<maxn ; i++)
    {
        parent[i]=i;
    }
}
void kruskals_Algorithm(ll n)
{
    sort(graph.begin(), graph.end(), compare);
    initPar(n);
    for(ll i=0; i<graph.size() ; i++)
    {
        ll uPr=Find(graph[i].u);
        ll vPr=Find(graph[i].v);

        if(uPr!=vPr)
        {
            if(cnt==n-1)
                break;
            output.pb(graph[i]);
            mstValue+=graph[i].w;
            parent[uPr]=vPr;
            cnt++;
        }
    }

}

void Init()
{
    for(ll i=0; i<maxn; i++)
    {
        parent[i]=i;
    }
}


int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, k, m, a, b, c, d, cs = 1;
    ll n, e;
    cin >> t;

    while(t--)
    {
        Init();
        ll total_cost = 0;
        graph.clear();
        output.clear();
        cin >> n;

        for(ll i=1 ; i<=n; i++)
        {
            for(int j=1,cost; j<=n; j++)
            {
                cin >> cost;
                total_cost+=cost;
                if(cost && i!=j)
                {
                    edge input;
                    input.u = i;
                    input.v = j;
                    input.w = cost;
                    graph.pb(input);
                }
            }
        }

        kruskals_Algorithm(n);

        cout << "Case " << cs++ << ": ";
        if(cnt!=n-1)
            cout << "-1" << endl;
        else
            cout << total_cost-mstValue << endl;
        mstValue = cnt = 0;
    }
    return 0;
}
