#include <bits/stdc++.h>
using namespace std;
#define ll long long

short n,m;
set<pair<short,short>> st;
vector<short> p[11];
ll fact[11];
bitset<11> used;
ll ans1 = 0;
short ans2 = 15;

void dfs(short id, short x){
    if(id > m){
        ans2 = min(ans2, x);

        if(x <= n){
            ans1 += fact[n] / fact[n-x];
        }
        return;
    }

    for(short i=1; i<=x; i++){
        bool valid = 1;
        for(short v: p[i]){
            if(st.count({v, id})){
                valid = 0;
                break;
            }
        }

        if(!valid) continue;
        
        p[i].push_back(id);
        dfs(id+1, x);
        p[i].pop_back();
    }

    p[x+1].push_back(id);
    dfs(id+1, x+1);
    p[x+1].pop_back();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>m>>n;
    fact[0] = 1;
    for(short i=1; i<=n; i++) fact[i] = fact[i-1] * i;

    short a,b;
    while(cin>>a>>b){
        if(a > b) swap(a,b);
        st.insert({a,b});
    }

    dfs(1,0);

    cout<<ans1<<'\n';
    cout<<ans2<<'\n';

}