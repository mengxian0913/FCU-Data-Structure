/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/22 13:25:35 2023
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
    int n, ans = 1;
    cin >> n;
    
    while(n > 0){
        ans *= (n--);
    }

    cout << ans << "\n";
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
