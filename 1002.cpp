#include<bits/stdc++.h>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl
using ll=long long;

struct data{
    int u, v, cost;
    data(){}
    data(int _u, int _v, int _cost){
          u = _u;
          v = _v;
          cost = _cost;
    }
};
vector<data>graph;
int dis[551];

void Bellman_Ford(int src, int nodes)
{
    for(int i=0; i<nodes; i++)dis[i]=INT_MAX;
    dis[src]=0;
    for(int j=1; j<nodes; j++){
          for(int i=0; i<graph.size(); i++){
                int cur = max(dis[graph[i].u], graph[i].cost);
                if(cur<dis[graph[i].v]){
                      dis[graph[i].v] = cur;
                }
                cur = max(dis[graph[i].v], graph[i].cost);
                if(cur<dis[graph[i].u]){
                      dis[graph[i].u] = cur;
                }
           }
    }
    graph.clear();
}

int main()
{
    int t=1, n, m, k;
    cin >> t;

    int cs=0;
    while(t--){
            scanf("%d %d", &n, &m);
            while(m--){
                   int u, v, w;
                   scanf("%d %d %d", &u, &v, &w);
                   graph.push_back(data(u, v, w));
            }
            int src;
            scanf("%d", &src);
            Bellman_Ford(src, n);

            printf("Case %d:\n", ++cs);
            for(int i=0; i<n; i++){
                    if(dis[i]==INT_MAX){
                         printf("Impossible\n");
                         continue;
                    }
                    printf("%d\n", dis[i]);
            }
    }
    return 0;
}
