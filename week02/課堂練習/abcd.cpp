/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五  9/22 13:51:20 2023
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

void solve()
{
    int n;
    cin >> n;

    vector<char> arr;

    for(int i=0;i<n;i++)
    {
        arr.pb('a' + i);
    }

    do 
    {
        for(char i : arr)
        {
            cout << i << " ";
        }
        cout << "\n";
    } while(next_permutation(all(arr)));
    
    return;
}

signed main()
{
    fastIO
    solve();
    return 0;
}
