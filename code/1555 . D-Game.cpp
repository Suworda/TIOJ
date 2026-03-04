#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int dp[2][5005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    int cnt=0, mx=0;
    char ty;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>ty;
            if(ty == '0'){
                dp[i%2][j] = min({
                    dp[(i-1)%2][j],
                    dp[i%2][j-1],
                    dp[(i-1)%2][j-1]
                }) + 1;
                
                cnt += dp[i%2][j];
                mx = max(mx, dp[i%2][j]);
            }else{
                dp[i%2][j] = 0;
            }
        }
    }

    cout<<cnt<<' '<<mx<<'\n';

}