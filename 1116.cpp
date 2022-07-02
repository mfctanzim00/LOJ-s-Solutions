#include<bits/stdc++.h>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl
using ll=long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t=1, n, m, k;
    cin >> t;

    int cs=0;
    while(t--){
            cin >> n;
            ll l=-1, r=-1;
            ll tmpN=n;
            while(tmpN){
                   tmpN>>=1;
                   ll p=tmpN;
                   if(tmpN==0)break;
                   ll q = n/tmpN;
                   if(p*q==n && ((p%2==1 && q%2==0) || (q%2==1 && p%2==0))){
                        l=p;
                        r=q;
                        break;
                   }
            }
            cout << "Case " << ++cs << ": ";
            if(l==-1){
                   cout << "Impossible\n";
            }
            else cout << l << " " << r << '\n';
    }
    return 0;
}
