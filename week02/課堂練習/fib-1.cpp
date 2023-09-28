#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 100005;

int dp[MAXN];


void solve(){
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for(int i = 0; i < n; i++){
        cout << "fib<" << i + 1 << ">: " << dp[i] << "\n";
    }

    return;
}

signed main(){
    solve();
    return 0;
}
