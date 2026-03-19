#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int S=2e9, T=0;
vector<pair<int,int>> seg;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        seg.push_back({l,r});
        S = min(S, l);
        T = max(T, r);
    }

    int x=S;
    int nxt=-1;
    int ans = 0;
    while(x < T){
        ans++;
        for(int i=0; i<n; i++){
            if(seg[i].first <= x+1) nxt = max(nxt, seg[i].second);
        }
        
        // cout<<nxt<<'\n';
        if(nxt == -1 || nxt == x){
            cout<<-1<<'\n';
            return 0;
        }

        x = nxt;
        
    }

    cout<<ans<<'\n';

}