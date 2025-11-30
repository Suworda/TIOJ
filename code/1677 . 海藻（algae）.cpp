#include <bits/stdc++.h>
using namespace std;

long long sz[50];

int f(int n, int k){
    if(n <= 1) return 0;
    else if(n == 2) return 1;

    if(k <= sz[n-2]) return f(n-2, k);
    else return f(n-1, k-sz[n-2]);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    sz[0]=0;
    sz[1]=1;
    sz[2]=1;
    for(int i=3; i<=50; i++){
        sz[i]=sz[i-1]+sz[i-2];
    }

    int m;
    cin>>m;
    int n,k;

    while(m--){
        cin>>n>>k;
        n=min(n,50);
        if(sz[n]<k){
            cout<<-1<<'\n';
            continue;
        }
        cout<<f(n,k)<<'\n';
    }

}
