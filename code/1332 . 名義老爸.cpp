#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int t[1000005];
int l[1000005], r[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        t[x] = i;
    }

    vector<int> stk(n+5);
    int top = -1;

    for(int i=1; i<=n; i++){
        int last = 0;
        while(top != -1 && t[i] < t[stk[top]]){
            last = stk[top];
            top--;
        }

        if(last) l[i] = last; 
        if(top != -1) r[stk[top]] = i;
        
        stk[++top] = i;
    }

    vector<int> pa(1000005);
    for(int i=1; i<=n; i++){
        pa[l[i]] = i;
        pa[r[i]] = i;
    }

    for(int i=1; i<=n; i++){
        cout<<pa[i]<<'\n';
    }

}