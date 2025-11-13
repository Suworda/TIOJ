#include <iostream>
#include <unordered_set>
using namespace std;

int n;
int a[10001];
int ans=0;

void check(int l, int r, int t){
    unordered_set<int> x,y;
    while(l>=0 && r<n){
        x.insert(a[l]);
        y.insert(a[r]);
        if(x == y) ans=max(ans, r-l+1);
        l--;
        r++;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n-1; i++){
        check(i,i+1,i);
    }

    cout<<ans<<'\n';

}
