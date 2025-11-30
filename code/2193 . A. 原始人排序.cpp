#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];

int cnt(int x){
    int ans=0;
    while(x){
        ans+=(x%2==1);
        x/=2;
    }
    return ans;
}

bool cmp(int x, int y){
    //1
    //return cnt(x) < cnt(y);

    //2
    return __builtin_popcount(x) < __builtin_popcount(y);
}

int main(){

    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    stable_sort(a, a+n, cmp);

    for(int i=0; i<n; i++){
        cout<<a[i];
        cout<<(i==n-1 ? '\n' : ' ');
    }

}

