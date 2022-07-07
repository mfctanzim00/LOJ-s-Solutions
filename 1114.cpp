#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl
const int mxNode=1e5+7;

int tree[mxNode][52];
int col, cnt[mxNode];
string ch;

int getVal(char c){
    if(c>='A' && c<='Z')return c-'A';
    return 26+c-'a';
}

void init(){
    col = 0;
    for(int i=0; i<52; i++){
        tree[0][i] = -1;
    }
}

void Insert(int n){
    int cur = 0;
    for(int i=0; i<n; i++){
        int f = getVal(ch[i]);
        if(tree[cur][f] == -1){
            tree[cur][f] = ++col;
            for(int j=0; j<52; j++){
                tree[col][j] = -1;
            }
            cnt[col]=0;
        }
        cur = tree[cur][f];
    }
    cnt[cur]++;
}

int solve(string str){
    int cur = 0;
    int len = str.size();
    for(int i=0; i<len; i++){
        int f = getVal(str[i]);
        if(tree[cur][f] == -1){
            return 0;
        }
        cur = tree[cur][f];
    }
    return cnt[cur];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t=1, n, m, cs=0;
    cin >> t;

    while(t--){
        cin >> n;
        init();

        for(int i=1; i<=n; i++){
            cin >> ch;
            int len = ch.size();
            if(len>2){
                sort(ch.begin()+1, ch.end()-1);
            }
            Insert(len);
        }
        cin >> m;
        cin.get();

        cout << "Case " << ++cs << ":\n";
        for(int i=1; i<=m; i++){
            getline(cin, ch);
            int ans=1;

            string str=ch;
            stringstream ss(str);
            string word;

            while(ss>>word){
                if(word.size()>2)sort(word.begin()+1, word.end()-1);
                ans*=solve(word);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
