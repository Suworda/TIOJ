#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[2000005];
int lim;

bool valid(ll h){
    int cnt = 0;
    int cur;
    for(int i=0; i<2*n; i++){
        if(a[i%n] >= h) cur = h;
        else cur = a[i%n];

        if(cur == h) cnt=0;
        else cnt++;

        if(cnt >= lim){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    lim = (n-1)/2;
    for(int i=0; i<n; i++) cin>>a[i];
    
    ll l=0, r=1e10, h=-1;
    while(l <= r){
        ll m = (l+r)/2;
        if(valid(m)){
            h = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++) ans += max(0ll, a[i] - h);

    cout<<ans<<'\n';

}