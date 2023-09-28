/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/22 14:39:13 2023
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

const int MAXN = 200;

vector<char> arr, res;
bool vis[MAXN];

int n;

void dfs(int depth){
    if(depth > n){
        for(char i : res){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            res.pb(arr[i]);
            dfs(depth + 1);
            res.pop_back();
            vis[i] = 0;
        }
    }
    return;
}


void solve(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        arr[i] = ('a' + i);
    }
    dfs(1);
    return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
