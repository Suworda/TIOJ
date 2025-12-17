#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int MAXN = 500000;
int n,m,a,b;
vector<int> nxt1[MAXN+5], nxt2[MAXN+5];
bitset<MAXN> vis1, vis2;
int deg1[MAXN+5], deg2[MAXN+5];
int ans1=0, ans2=0;

void init(){
    for(int i=0; i<n; i++) nxt1[i].clear(), nxt2[i].clear();
    for(int i=0; i<n; i++) deg1[i]=0, deg2[i]=0;
    vis1.reset(), vis2.reset();
    ans1=0, ans2=0;
}

void sol(){
    cin>>n>>m;
    init();

    for(int i=0; i<m; i++){
        cin>>a>>b;
        nxt1[a].push_back(b);
        nxt1[b].push_back(a);
        deg1[a]++;
        deg1[b]++;

        nxt2[a].push_back(b);
        nxt2[b].push_back(a);
        deg2[a]++;
        deg2[b]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(vis1[i]) continue;

        q.push(i);
        while(q.size()){
            int v = q.front();
            q.pop();
            ans1 = max(ans1, deg1[v]);

            for(int u: nxt1[v]){
                deg1[u]--;
                if(!vis1[u]){
                    vis1[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    
    priority_queue<pii , vector<pii> , greater<pii>> pq;
    for(int i=0; i<n; i++){
        pq.push({deg2[i],i});
    }


    for(int i=0; i<n && pq.size();){
        auto [x,v] = pq.top();
        pq.pop();
        if(vis2[v]) continue;

        ans2 = max(ans2, x);
        vis2[v] = 1;
        
        for(int u: nxt2[v]){
            if(!vis2[u]){
                deg2[u]--;
                pq.push({deg2[u],u});
            }
        }
        i++;
    }

    cout<<ans1<<' '<<ans2<<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}