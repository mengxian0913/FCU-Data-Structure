/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 10/ 6 15:24:11 2023
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

const int MAXN = 8;

int bin_to_dec(string ss) {
  int dec = 0, base = 0;
  for(int i=ss.size()-1; i >= 0; i--) {
    dec += (int)(ss[i] - '0') << (base++);
  }
  return dec;
}

string Dec_to_Bin(int num) {
  
  int bin[MAXN];
  bool ch = false;
  if(num < 0) {
    num *= -1;
    ch = true;
  }
  
  for(int i=0; i<MAXN; i++) {
    bin[i] = (num >> i) & 1;
  }
  
  if(ch) {
    for(int i=0;i<MAXN;i++) {
      bin[i] ^= 1;
    }
    int ind = 0;
    bin[ind]++;
    while(bin[ind] > 1) {
      bin[ind] = 0;
      bin[ind++]++;
    }
  }
  
  string res = "";
  for(int i=MAXN-1; i >= 0; i--) {
    res += to_string(bin[i]);
  }
  
  return res;
}

void solve(){
  freopen("./hw2.txt", "r", stdin);
  freopen("./result.txt", "w", stdout);
  string num1, num2, sign;
  while(cin >> num1 >> sign >> num2) {
    int n1 = bin_to_dec(num1), n2 = bin_to_dec(num2), ans = 0;  
    if(sign == "+") {
      ans = n1 + n2;
    } else { 
      ans = n1 - n2;
    }
  
    cout << num1 << " " << sign << " " << num2 << " = " << Dec_to_Bin(ans) << "(" << n1 << " " << sign << " " << n2 << " = " << ans << ")\n";
  }
   
  fclose(stdin);
  fclose(stdout);
  return;
}

signed main(){
    fastIO
    solve();
    return 0;
}
