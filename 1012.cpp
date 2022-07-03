#include<bits/stdc++.h>
using namespace std;
#define bug(a) cerr<<#a<<" : "<<a<<endl

char ch[20][20];
int n, m, ans;

void Dfs(int r, int c)
{
    if(r<0 || r==n || c<0 || c==m || ch[r][c]=='#')return;
    ans++;
    ch[r][c]='#';

    Dfs(r+1, c);
    Dfs(r, c+1);
    Dfs(r-1, c);
    Dfs(r, c-1);
}

int main()
{
    int t=1, k;
    scanf("%d", &t);

    int cs=0;
    while(t--){
            scanf("%d %d", &m, &n);
            int r, c;
            getchar();
            for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                            scanf("%c", &ch[i][j]);
                            if(ch[i][j]=='@')r=i, c=j;
                    }
                    getchar();
            }
            ans=0;
            Dfs(r, c);
            printf("Case %d: %d\n", ++cs, ans);
    }
    return 0;
}
