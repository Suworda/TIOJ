#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,k;
unsigned int h[10000005];
int dq1[10000005], dq2[10000005];
int front1 = 0, front2 = 0, back1 = -1, back2 = -1;
vector<pair<int,int>> ans;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }

    for(int i=1; i<=n; i++){
        while(front1 <= back1 && dq1[front1] <= i-m) front1++;
        while(front2 <= back2 && dq2[front2] <= i-m) front2++;

        while(front1 <= back1 && h[i] > h[dq1[back1]]) back1--;
        while(front2 <= back2 && h[i] < h[dq2[back2]]) back2--;

        dq1[++back1] = i;
        dq2[++back2] = i;
        if(h[dq1[front1]] - h[dq2[front2]] == k) ans.push_back({max(1,i-m+1), i});
    }

    for(int i=n+1; i<=n+m; i++){
        while(front1 <= back1 && dq1[front1] <= i-m) front1++;
        while(front2 <= back2 && dq2[front2] <= i-m) front2++;

        if(front1 <= back1 && front2 <= back2 && h[dq1[front1]] - h[dq2[front2]] == k) ans.push_back({i-m+1, n});
    }

    cout<<ans.size()<<'\n';
    for(auto &[l,r]: ans){
        cout<<l<<' '<<r<<'\n';
    }

}