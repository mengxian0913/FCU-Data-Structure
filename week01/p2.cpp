/*********************************************************
# File Name: p2.cpp
# Author: Vincent Yang
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/15 14:00:40 2023
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
    srand(time(NULL));

    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int k=0; k<n;k++){
            cout << (rand()%100 + 100) << "\t";
        }
        cout << "\n";
    }
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
