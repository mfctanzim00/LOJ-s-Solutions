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
const ll mod = 1e9+7;
const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    ll t=1, n, k, m, a, b, c, d, cs=0;
    cin >> t;

    while(t--){
            cin >> a >> b;
            cout << "Case " << ++cs << ": ";
            ll diff=a-b;
            set<ll>s;
            ll sq=sqrt(a-b);
            for(ll i=1; i<=sq; i++){
                     if(diff%i)continue;
                     if(diff/i>b)s.insert(diff/i);
                     if(i>b)s.insert(i);
            }
            if(s.empty())cout << "impossible" << '\n';
            else{
                    ll cnt=0;
                    for(auto x: s){
                            ++cnt;
                            if(cnt==s.size())cout << x << '\n';
                            else cout << x << " ";
                    }
            }
    }
    return 0;
}
