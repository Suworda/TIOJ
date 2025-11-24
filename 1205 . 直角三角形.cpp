#include <bits/stdc++.h>
using namespace std;

signed main(){
//    ios::sync_with_stdio(false);
//    cin.tie();
    int n;
    while(cin>>n && n!=0){
        long long ans=0;
        int x[n],y[n];
        for(int i=0; i<n; i++){
            cin>>x[i]>>y[i];
        }

        for(int i=0; i<n; i++){
            map< pair<int,int> , int > cnt;
            for(int j=0; j<n; j++){
                if(i==j) continue;

                int dx=x[i]-x[j];
                int dy=y[i]-y[j];

                int g = gcd(dx,dy);
                dx/=g;
                dy/=g;

                ans += cnt[{-dy,dx}] + cnt[{dy,-dx}];

                cnt[{dx,dy}]++;
            }
        }
        cout<<ans<<'\n';

    }

}
