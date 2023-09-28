/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/22 13:21:14 2023
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

int f(int now){
    if(now <= 0){
        return 0;
    }

    return now * (now - 1) + f(now - 1);
}

void solve(){
    int n;
    cin >> n;
    cout << f(n) << "\n";
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
