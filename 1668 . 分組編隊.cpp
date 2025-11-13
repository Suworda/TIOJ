#include <iostream>
#include <vector>
using namespace std;

void query(){
    int l,r;
    cin>>l>>r;
    vector<bool> not_p(r-l+1);

    for(long long i=2; i*i<=r; i++){ //注意i*i可能會超過int上限
        long long v = l/i*i;
        if(v!=l) v+=i;

        for(; v<=r; v+=i){
            if(v <= i) continue;
            not_p[v-l]=true;
        }
    }

    int ans=0;
    for(auto x: not_p){
        ans+=(!x);
        //cout<<(!x)<<' ';
    }

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) query();
}
