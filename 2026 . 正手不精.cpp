#include <bits/stdc++.h>
using namespace std;
#define ll long long

int q;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>q;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int x;
            cin>>x;
            if(r.size() && x < r.top()) l.push(x);
            else r.push(x);
            
        }else{
            cout << r.top() << '\n';
        }

        while(r.size() > l.size()+1){
            int x = r.top(); r.pop();
            l.push(x);
        }

        while(l.size() > r.size()){
            int x = l.top(); l.pop();
            r.push(x);
        }

    }

}