#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    int last=-1;
    int ans=0;
    while(true){
        cin>>x;
        if(x==0 && last==0) break;
        last=x;
        if(x==0){
            cout<<ans<<'\n';
            ans=0;

        }else{
            ans+=(1 << __lg(x));
        }
//        cout<<ans<<'\n';
    }

}
