#include <iostream>
#include <unordered_set>
using namespace std;

int n;
int a[10001];
int ans=0;

void check(int l, int r){
    unordered_set<int> x, y, same;
    while(l>=0 && r<n){
        if(a[l] == a[r]){
            same.insert(a[l]);
            x.erase(a[l]);
            y.erase(a[r]);
        }else{

            if(!same.count(a[l])){
                if(y.count(a[l])){
                    same.insert(a[l]);
                    x.erase(a[l]);
                    y.erase(a[l]);

                }else{
                    x.insert(a[l]);
                }

            }

            if(!same.count(a[r])){
                if(x.count(a[r])){
                    same.insert(a[r]);
                    x.erase(a[r]);
                    y.erase(a[r]);

                }else{
                    y.insert(a[r]);
                }

            }

        }

//        for(int cur: x) cout<<cur<<' ';
//        cout<<'\n';
//        for(int cur: y) cout<<cur<<' ';
//        cout<<'\n'<<'\n';

        if(x.empty() && y.empty()) ans = max(ans, r-l+1);

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
        check(i,i+1);
    }

    cout<<ans<<'\n';

}
