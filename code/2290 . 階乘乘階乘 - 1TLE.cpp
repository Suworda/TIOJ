#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1e7;

int cnt_a[MAX_V+5];
int cnt_b[MAX_V+5];
int d_a[MAX_V+5];
int d_b[MAX_V+5];
int spf[MAX_V+5];
vector<int> prime;

signed main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    for(int i=2; i<=MAX_V; i++){
        //cout<<i<<'\n';
        if(spf[i]==0){
            prime.push_back(i);
            spf[i]=i;
        }

        for(auto &p: prime){
            if(p > spf[i] || 1LL*i*p > MAX_V) break;
            spf[i*p]=p;
        }
        //cout << i << ':' << spf[i] << '\n';
    }
    int n,m;
    cin>>n>>m;

//    for(int i=2; i<=100; i++) cout << i << ':' << spf[i] << '\n';
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a;
        d_a[a]++;
    }
    //return 0;
    for(int i=0; i<m; i++){
        cin>>b;
        d_b[b]++;
    }


    int cur=0,x;
    for(int i=MAX_V; i>=2; i--){
        cur+=d_a[i];
        x=cur;
        while(x>=2){
            cnt_a[spf[x]]++;
            x/=spf[x];
        }
    }

    cur=0;
    for(int i=MAX_V; i>=2; i--){
        cur+=d_b[i];
        x=cur;
        while(x>=2){
            cnt_b[spf[x]]++;
            x/=spf[x];
        }
    }

    for(int i=2; i<=MAX_V; i++){
        if(cnt_a[i]<cnt_b[i]){
            cout<<"No\n";
            return 0;
        }
    }

    cout<<"Yes\n";


}

