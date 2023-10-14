/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 10/13 13:21:31 2023
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


MyPoly::MyPoly() {

}


MyPoly::MyPoly(char* filename) {
  FILE *fptr = NULL;
  fptr = fopen(filename, "r");
  size = 0;
  while(!feof(fptr)) {
    fscanf(fptr, "%d %d", &terms[size].coef, &terms[size].expon);
    size++;
  }
}


void solve(){
  
}



signed main(){
  fastIO
  solve();
  return 0;
}
