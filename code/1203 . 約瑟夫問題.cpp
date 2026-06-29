#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f_ai(ll n, ll k, ll m) {
    // 【步驟 1】案發現場
    // 遊戲剛好殺到剩下 m+1 個人，下一槍就要打死目標了！
    // 這一槍永遠打在 (k-1) % n 的位子上。
    if (n == m + 1) return (k - 1) % n;
    
    // 【步驟 2】宇宙太小，沒辦法快轉
    // 如果每次要數的 K，比現在活著的人 N 還多，那就殺不快。
    // 乖乖退回原本的 O(N) 暴力解，一步一步走。
    if (k > n) return (f_ai(n - 1, k, m) + k) % n;
    
    // ============ 快轉魔法開始 ============
    
    // 【步驟 3】一口氣大屠殺
    // 算出這輪可以直接殺掉幾個人
    ll y = n / k;
    
    // 【步驟 4】攔截！目標在這次大屠殺中死了嗎？
    // 如果殺完 y 個人之後，剩下的人數 <= m，代表目標的死期就在這批人裡面！
    if (n - y <= m) {
        // 他是這局裡面「第 (n - m) 個死掉的」。
        // 因為每 K 個人死一個，所以他的真實位子就是 (n - m) * K - 1。
        // 抓到人了！直接結束！
        return (n - m) * k - 1; 
    }
    
    // 【步驟 5】目標逃過一劫，繼續去未來找他
    // 目標沒死在這批，他順利進入了「剩下 n-y 個人」的新宇宙。
    // 去問新宇宙，他活下來的新編號 (x) 是多少？
    ll x = f_ai(n - y, k, m);
    
    // 【步驟 6】填補死人坑洞 (最神奇的一步)
    // 我們拿到了他在新宇宙的編號 x，準備還原他在舊宇宙的真實位子。
    
    // 6-a: 修正起點偏移 (這批屠殺最後剩下幾個沒數到的人，要先扣掉)
    x -= (n % k); 
    
    // 6-b: 計算身後的「死人坑」
    if (x < 0) {
        // 如果扣完變負的，代表他一開始坐在這條馬路的最尾端。
        // 直接把他繞回尾巴就好。
        x += n;   
    } else {
        // 🌟 小明的算數學時間！
        // 真實位子 = 自己(活人)的編號 + 前面經過的「死人坑」數量
        // 因為每 (k-1) 個活人，就會夾著 1 個死人坑，所以坑數就是 x / (k-1)。
        x += (x / (k - 1)); 
    }
    
    return x;
}

int f_ai_2(int n, int k, int m){
    if (n == m + 1) return (k - 1) % n;
    
    if (k > n) return (f_ai_2(n - 1, k, m) + k) % n;
    
    ll y = n / k;
    
    if (n - y <= m) return (n - m) * k - 1; 
    
    ll x = f_ai_2(n - y, k, m);
    x -= (n % k); 
    
    if(x < 0) x += n;   
    else x += (x / (k - 1));
    
    return x;
}

int f(int n, int k, int m){
    int y = n/k;
    if(n < m+1){
        cerr<<"error\n";
        return NAN;
    }
    if(n == m+1) return (k-1)%n;
    int x = f(n-y, k, m);

    return (x+k*y)%n;
}


void sol(int n, int k, int m){
    cout << f_ai_2(n, k, m)+1 << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k;
    while(cin>>n>>k>>m && n!=0) sol(n,k,m);
}