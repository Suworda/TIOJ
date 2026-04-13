#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
string s;
int a[2000001];
ll ans = 0;
pair<int,int> dq[2000001];
ll sum[2000001];
int front = 1, back = 0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>s;
    for(int i=1; i<=n; i++) cin>>a[i];

    int cnt = 0;
    dq[++back] = {0,0};

    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + a[i];
        cnt += (s[i-1] == '1');
        while(front <= back && cnt - dq[front].first > k) front++;

        while(front <= back && sum[i] <= sum[dq[back].second]) back--;

        dq[++back] = {cnt, i};
        ans = max(ans, sum[i] - sum[dq[front].second]);
    }
    cout<<ans<<'\n';
}