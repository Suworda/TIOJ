#include <bits/stdc++.h>
using namespace std;
#define ll long long
using Grid = array<array<int,3>, 3>;

void sol(Grid s, Grid t){
    map<Grid, int> rst;
    queue<Grid> q;
    rst[s] = 0;
    q.push(s);

    while(q.size()){
        Grid cur = q.front(); q.pop();

        if(cur == t){
            cout << rst[t] << '\n';
            return;
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Grid x = cur;
                if(i-1 >= 0){
                    if(cur[i][j] == 0 || cur[i-1][j] == 0){
                        swap(x[i][j], x[i-1][j]);
                        if(rst.find(x) == rst.end()){
                            q.push(x);
                            rst[x] = rst[cur]+1;
                        }
                        swap(x[i][j], x[i-1][j]);
                    }
                }

                if(j-1 >= 0){
                    if(cur[i][j] == 0 || cur[i][j-1] == 0){
                        swap(x[i][j], x[i][j-1]);
                        if(rst.find(x) == rst.end()){
                            q.push(x);
                            rst[x] = rst[cur]+1;
                        }
                        swap(x[i][j], x[i][j-1]);
                    }
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Grid s, t;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>s[i][j];
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>t[i][j];
        }
    }

    sol(s, t);
}