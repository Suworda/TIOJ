#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,q;

void sol(){
    vector<pair<int,int>> seg;
    while(q--){
        int l,r;
        cin>>l>>r;
        seg.push_back({r,l});
    }
    sort(seg.begin(), seg.end());

    int last = -1, ans = 0;
    for(auto [r,l]: seg){
        if(!(l <= last && last <= r)){
            ans++;
            last = r;
        }
        // cout<<l<<' '<<r<<' '<<ans<<'\n';
    }

    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>n>>q) sol();
    

}