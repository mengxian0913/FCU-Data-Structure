/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/22 13:59:20 2023
*********************************************************/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define INF 0x7FFFFFFF
#define pb push_back
#define all(aa) aa.begin(),aa.end()
#define MOD (int)(1e9+7)

const int MAXN = 100005;

int dp[MAXN];

int fib(int now){

    if(now == 1 || now == 2){
        return 1;
    }
    
    if(!dp[now - 1]){
        dp[now - 1] = fib(now - 1);
    }

    if(!dp[now - 2]){
        dp[now - 2] = fib(now - 2);
    }
    
    dp[now] = dp[now - 1] + dp[now - 2];
    return dp[now - 1] + dp[now - 2];
}

void solve(){
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    fib(n);

    for(int i=1;i<=n;i++){
        cout << dp[i] << " ";
    }
    cout << "\n";
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
