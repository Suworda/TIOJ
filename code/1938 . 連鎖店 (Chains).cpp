#include <bits/stdc++.h>
using namespace std;
int m,n,a,b,c,d;
int dp[105][205][205];
signed main(){
    cin>>m>>n>>a>>b>>c>>d;
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int x=i; x<=m; x++){
            for(int y=i; y<=m; y++){
                dp[i][x][y] = max(max(dp[i][x-1][y], dp[i][x][y-1]) , dp[i-1][x-1][y-1] + (a*(i-1) + b*(x-1) + c*(y-1))%d);
                ans = max(ans, dp[i][x][y]);
            }
        }
    }
    cout<<ans<<'\n';
}