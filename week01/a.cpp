/*********************************************************
# File Name: a.cpp
# Author: Vincent Yang
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/15 13:59:09 2023
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

unordered_set<int> ms;

int GetRand(){
    while(1){
        int now = rand()%100 + 101;
        if(!ms.count(now)){
            ms.insert(now);
            return now;
        }
    }
    return -1;
}

void solve(){
    srand(time(0));
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            cout << GetRand() << "\t";
        }
        cout << "\n";
    }
}

signed main(){
    fastIO
    solve();
    return 0;
}
