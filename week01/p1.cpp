/*********************************************************
# File Name: a.cpp
# Author: Vincent Yang
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/15 13:45:55 2023
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
#define MOD 1e9+7

void solve(){
    for(int i=1;i<=9;i++){
        for(int k=1;k<=9;k++){
            printf("%lld*%lld=%lld\t", i, k, i * k);
        }
        puts("");
    }
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
