/*********************************************************
# File Name: a.cpp
# Author: Vincent Yang
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/15 13:54:26 2023
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

int is_prime(int n){
    
    if(n < 2){
        return 0;
    }

    for(int i=2; i<sqrt(n);i++){
        if(!(n % i)){
            return 0;
        }
    }

    return 1;
}

void solve(){
    int n;
    cin >> n;
    cout << is_prime(n) << "\n";
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
