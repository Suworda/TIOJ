#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> v{0,1};
vector<int> ans_v;
int ans = 0;

void dfs(int x){
    if(x > n){
        ans_v = max(ans_v, v);
        ans++;
        return;
    }

    for(int i=0; i<v.size()-1; i++){
        int y = v[i]+v[i+1];
        if(x >= y && x%y == 0){
            v.insert(v.begin()+i+1, x);
            dfs(x+1);
            v.erase(v.begin()+i+1);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    dfs(2);

    cout<<ans<<'\n';
    for(int x: ans_v) cout<<x<<' ';
    cout<<'\n';

}