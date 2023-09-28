/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/22 14:21:07 2023
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

int n;

vector<int> arr;

void dfs(int depth){
    if(depth > n){
        for(int i : arr){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    arr.pb(0);
    dfs(depth + 1);
    arr.pop_back();

    arr.pb(1);
    dfs(depth + 1);
    arr.pop_back();

    return;
}

void solve(){
    cin >> n;
    dfs(1);
}

signed main(){
    fastIO
    solve();
    return 0;
}
