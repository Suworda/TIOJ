#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[1000005], b[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    sort(a, a+n);
    sort(b, b+n);
    
    ll ans=0;
    for(int i=0; i<n; i++) ans += abs(a[i] - b[i]);

    cout<<ans<<'\n';
}