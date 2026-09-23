#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long


void sol(int n){
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        pq.push(x);
    }

    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        ans += (a+b);
        pq.push(a+b);
    }
    
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while(cin>>n) sol(n);

}