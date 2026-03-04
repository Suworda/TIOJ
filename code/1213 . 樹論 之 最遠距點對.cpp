#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge{
    int u,w;
};

const int MAXN = 100005;

pair<int,int> dp[MAXN];
int n;
vector<Edge> nxt[MAXN];
bitset<MAXN> vis;

void init(){
    vis.reset();
    for(int i=1; i<=n; i++){
        nxt[i].clear();
        dp[i] = {0,0};
    }
}

pair<int,int> dfs(int v){
    //if(!nxt[v].size()) return {0,0};
    
    //dp[v] = max(dp[u].f + dp[u].s + w , dp[u].f + x + w) 
    for(auto &[u,w]: nxt[v]){
        if(!vis[u]){
            vis[u] = 1;
            auto rst = dfs(u);
            if(rst.first + w > dp[v].first){
                dp[v].second = dp[v].first;
                dp[v].first = rst.first + w;
    
            }else if(rst.first + w > dp[v].second){
                dp[v].second = rst.first + w;
            }
        }else{
        }
    }

    return {dp[v].first, dp[v].second};

    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n && n!=0){
        init();
        for(int i=0; i<n-1; i++){
            int a,b,c;
            cin>>a>>b>>c;
            nxt[a].push_back({b,c});
            nxt[b].push_back({a,c});
        }

        vis[1] = 1;
        dfs(1);

        int ans = 0;
        for(int i=1; i<=n; i++){
            // cout<<dp[i].first+dp[i].second<<'\n';
            ans = max(ans, dp[i].first + dp[i].second);
        }

        cout<<ans<<'\n';
    }

}