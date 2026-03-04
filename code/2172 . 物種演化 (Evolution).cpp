#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
bitset<MAXN> vis;
vector<int> edge[MAXN];
int in[MAXN], out[MAXN];
int nxt[MAXN][32];
int dep[MAXN];
int n,m;
int now_t=1;

void dfs(int v){
    in[v] = now_t++;
    for(int u: edge[v]){
        if(!dep[u]){
            nxt[u][0] = v;
            dep[u] = dep[v]+1;
            dfs(u);
        }
    }
    out[v] = now_t++;
}

void build(){
    for(int i=1; i<21; i++){
        for(int v=0; v<n; v++){
            nxt[v][i] = nxt[nxt[v][i-1]][i-1];
        }
    }
}

bool valid(int x, int y){
    if(in[x] <= in[y] && out[x] >= out[y]) return true;
    return false;
}

int query(int x, int y){
    // cout<<"ok";
    if(in[x] <= in[y] && out[x] >= out[y]) return abs(dep[x] - dep[y]);
    else if(in[x] >= in[y] && out[x] <= out[y]) return abs(dep[x] - dep[y]);

    int p = x;
    for(int i=20; i>=0; i--){
        if(!valid(nxt[p][i], y)){
            p = nxt[p][i];
        }
    }
    p = nxt[p][0];

    return abs(dep[x] - dep[p]) + abs(dep[p] - dep[y]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    dep[0]= 1;
    dfs(0);
    build();
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<21; j++){
    //         cout<<i<<' '<<j<<' '<<nxt[i][j]<<'\n';
    //     }
    // }
    
    // for(int i=0; i<n; i++){
    //     cout<<in[i]<<' '<<out[i]<<'\n';
    // }

    while(m--){
        // cout<<in[1]<<' '<<in[8]<<' '<<out[1]<<' '<<out[8]<<'\n';
        int x,y;
        cin>>x>>y;
        // cout<<"ok"<<'\n';
        cout<<query(x,y)<<'\n';
    }
}