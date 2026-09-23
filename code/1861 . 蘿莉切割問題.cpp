#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int V = 10000;
const int N = 100005;

int n;
int cnt[V+1];
int b[N];

void sol(){
    memset(cnt, 0, sizeof(cnt));

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    int p = 1;
    int l = 0, r = 0;

    auto get_min = [&]() -> int {
        while(p <= V && cnt[p] == 0) p++;

        if(p > V)
            return b[l++];

        if(l == r || p <= b[l]){
            cnt[p]--;
            return p;
        }

        return b[l++];
    };

    ll ans = 0;

    for(int i=0; i<n-1; i++){
        int x = get_min();
        int y = get_min();

        ans += x + y;
        b[r++] = x + y;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n) sol();
}