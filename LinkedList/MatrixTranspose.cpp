/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 四 11/ 9 11:24:43 2023
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
#define MAXN (int)(1e5 + 10)

struct matrix {
  int row;
  int col;
  int val;
};

struct transpose {
  int total;
  int first_index;
};

matrix MatA[MAXN], MatB[MAXN];
transpose tran[MAXN];


void solve(){
  int n, m, t;
  cin >> n >> m >> t;

  MatA[0].row = MatB[0].col =  n;
  MatA[0].col = MatB[0].row = m;
  MatA[0].val = MatB[0].val = t;
  for(int i = 1; i <= t; i++) {
    cin >> MatA[i].row >> MatA[i].col >> MatA[i].val;
    tran[MatA[i].col].total++;
  }

  cout << "Matrix A:\n";
  for(int i = 0; i <= t; i++) {
    cout << MatA[i].row << " " << MatA[i].col << " " << MatA[i].val << "\n";
  }
  cout << "\n";

  int cnt = 0;
  for(int i = 0; i < m; i++) {
    cnt += tran[i].total;
    tran[i].first_index = cnt;
  }


  for(int i = 1; i <= t; i++) {
    int idx = tran[MatA[i].col].first_index;
    MatB[idx].row = MatA[i].col;
    MatB[idx].col = MatA[i].row;
    MatB[idx].val = MatA[i].val;
    tran[MatA[i].col].first_index++;
  }

  cout << "Matrix B:\n";
  for(int i = 0; i <= t; i++) {
    cout << MatB[i].row << " " << MatB[i].col << " " << MatB[i].val << "\n";
  }
  
  
  return;
}

signed main(){
  fastIO
  solve();
  return 0;
}
