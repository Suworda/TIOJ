#include <bits/stdc++.h>
using namespace std;

int p[200005]={};
int ans[200005]={};
vector<int> v;
set<int> id;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n,k;
    cin>>n>>k;
    int a;
    for(int i=1; i<=n; i++){
        cin>>a;
        p[a]=i;
        v.push_back(a);
        id.insert(i);
    }
    sort(v.begin(), v.end(), greater<>());

    int team=1;

    for(int cur: v){
        if(ans[p[cur]] == 0){
            auto it = id.lower_bound(p[cur]);
            for(int i=0; i<=k && it!=id.end() ; i++){
                ans[*it]=team;
                it = id.erase(it);
            }

            for(int i=0; i<k && it!=id.begin() ; i++){
                it--;
                ans[*it]=team;
                it = id.erase(it);
            }
            if(team == 1) team=2;
            else team=1;
        }

    }

    for(int i=1; i<=n; i++) cout<<ans[i];
    cout<<'\n';

}

/*
5 2
1 2 3 5 4

*/
