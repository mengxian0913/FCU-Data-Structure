/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/22 13:36:16 2023
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

void solve(){
    int n, ans = 0;
    cin >> n;
    for(int i=1;i<=n-1;i++){
        ans += (i * (i + 1));
    }
    cout << ans << "\n";
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
