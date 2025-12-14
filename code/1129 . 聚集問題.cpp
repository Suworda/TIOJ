#include <bits/stdc++.h>
using namespace std;

int a,b,c;
vector<pair<int,int>> p;
vector<int> ans_v;
bool vis[4005];

void init(){
    p.clear();
    ans_v.clear();
    for(int i=0; i<4005; i++){
        vis[i] = false;
    }
}

bool valid(int idx1, int idx2){
    auto [x1,y1] = p[idx1];
    auto [x2,y2] = p[idx2];
    int dx = abs(x1-x2);
    int dy = abs(y1-y2);

    return dx*dx + dy*dy <= c*c;
}

void bfs(int idx){
    queue<int> q;
    int cnt=0;

    q.push(idx);
    vis[idx] = true;

    while(!q.empty()){
        cnt++;
        idx = q.front();
        q.pop();
        for(int i=0; i<b; i++){
            if(!vis[i] && valid(idx,i)){
                q.push(i);
                vis[i] = true;
            }
        }
    }

    ans_v.push_back(cnt);
}

void sol(){
    init();

    int X,Y;
    for(int i=0; i<b; i++){
        if(i==0){
            X = (269*a+11)%103;
            Y = (271*a+13)%97;
            p.push_back({X,Y});
        }else{
            X = (269*X+11)%103;
            Y = (271*Y+13)%97;
            p.push_back({X,Y});
        }
    }

    for(int i=0; i<b; i++){
        if(!vis[i]) bfs(i);
    }

    sort(ans_v.begin(), ans_v.end());

    cout<<ans_v.size()<<'\n';
    for(int cnt: ans_v){
        cout<<cnt<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>a>>b>>c) sol();

}