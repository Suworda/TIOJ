#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        unsigned int cur=0;
        unsigned int x;
        for(int i=0; i<n; i++){
            cin>>x;
            cur^=x;
        }
        cout<<cur<<'\n';
    }



}
