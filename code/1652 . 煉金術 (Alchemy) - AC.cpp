#include <bits/stdc++.h>
using namespace std;

short int apr_l[10000005]={};
short int apr_r[10000005]={};

int n;
int a[10001];
int ans=0;
int diff=0;

void check(int l, int r){
    int t=r;
    diff=0;
    while(l>=0 && r<n){
        if(a[l]!=a[r]){
            if(apr_l[a[r]] != t && apr_r[a[r]] != t){
                diff++;
            }

            if(apr_r[a[l]] != t && apr_l[a[l]] != t){
                diff++;
            }
        }

        if(apr_l[a[l]] != t && apr_r[a[l]] == t){
            diff--;
        }

        if(apr_r[a[r]] != t && apr_l[a[r]] == t){
            diff--;
        }

        //cout<<diff<<'\n';
        if(diff==0) ans=max(ans,r-l+1);

        apr_l[a[l]]=t;
        apr_r[a[r]]=t;

        l--;
        r++;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    //check(4,5);

    for(int i=0; i<n; i++){
        check(i, i+1);
    }

    cout<<ans<<'\n';

}

/*
10
10000000 10000000 43929 2 43895 43929 93939 2 43939 43895
*/
