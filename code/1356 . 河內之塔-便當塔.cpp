#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int x;

void go(int n);
void back(int n);

void go(int n){
    if(n == 0) return;
    
    go(n-1);
    cout<<"#"<<(++x)<<" : move the dish from #"<<1<<" to #"<<2<<'\n';
    back(n-1);
    cout<<"#"<<(++x)<<" : move the dish from #"<<2<<" to #"<<3<<'\n';
    go(n-1);
}

void back(int n){
    if(n == 0) return;

    back(n-1);
    cout<<"#"<<(++x)<<" : move the dish from #"<<3<<" to #"<<2<<'\n';
    go(n-1);
    cout<<"#"<<(++x)<<" : move the dish from #"<<2<<" to #"<<1<<'\n';
    back(n-1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    go(n);

}