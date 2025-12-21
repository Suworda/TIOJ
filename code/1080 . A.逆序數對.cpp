#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int b[100005];

int query(int x){
    int rst=0;
    while(x){
        rst += b[x];
        x -= (x & -x);
    }
    return rst;
}

void update(int x){
    while(x <= n){
        b[x]++;
        x += (x & -x);
    }
}

void sol(){
    t++;
    for(int i=0; i<=n; i++){
        b[i] = 0;
    }
    vector<int> a;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        a.push_back(x);
    } 
    vector<int> b(a);

    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    for(int i=0; i<n; i++){
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        a[i] = it - b.begin() +1; 
    }

    long long ans=0;

    //for(int i=0; i<n; i++) cout<<a[i]<<'\n';
    for(int i=0; i<n; i++){
        ans += i - query(a[i]);
        //cout<<query(a[i])<<'\n';
        update(a[i]);
    }

    cout<<"Case #"<<t<<": "<<ans<<'\n';
    



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n && n) sol();

}