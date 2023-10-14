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

struct MyBin {
  int num1, num2;
  bool overflow;
  int bin_to_dec(string);
  pair<int, string> Dec_to_Bin(int);
};


int MyBin::bin_to_dec(string ss) {
  int dec = 0, base = 0;
  for(int i=ss.size()-1; i >= 0; i--) {
    dec += (int)(ss[i] - '0') << (base++);
  }
  return dec;
}

pair<int, string> MyBin::Dec_to_Bin(int num) {

  deque<int> bin;
  bool ch = false;
  int sign = 0;
  if(num < 0) {
    num *= -1;
    ch = true;
    sign = 1;
  }
  
  while(num) {
    bin.pb(num & 1);
    num >>= 1;
  }

  overflow = false;
  
  if(bin.size() > MAXN) {
    overflow = true;
  }


  while(bin.size() < MAXN) {
    bin.pb(0);
  }

  if(ch) {
    for(int i=0;i<MAXN;i++) {
      bin[i] ^= 1;
    }
    int ind = 0;
    bin[ind]++;
    while(bin[ind] > 1) {
      bin[ind] = 0;
      ind++;
      if(ind >= MAXN) {
        overflow = true;
        break;
      }
      bin[ind]++;
    }
  }
  
  string res = "";
  for(int i = MAXN - 1; i >= 0; i--) {
    res += to_string(bin[i]);
  }

  return {sign, res};
}

string full(string now) {
  while(now.size() < MAXN) {
    now = "0" + now;
  }
  return now;
}


void solve(){ 
  MyBin bin;
  string num1, num2, sign;
  while(cin >> num1 >> sign >> num2) {
    bin.num1 = bin.bin_to_dec(num1), bin.num2 = bin.bin_to_dec(num2);
    int result = 0;  
    if(sign == "+") {
      result = bin.num1 + bin.num2;
    } else { 
      result = bin.num1 - bin.num2;
    }
  
    pair<int, string> ans = bin.Dec_to_Bin(result);
    cout << full(num1) << " " << sign << " " << full(num2) << " = " << ans.ff << " " << ans.ss << " ( " << bin.num1 << " " << sign << " " << bin.num2 << " = " << result << " ) "
    << (bin.overflow ? "(* Overflow)\n" : "\n");
  }
   
  return;
}

signed main(){
  fastIO
  freopen("./hw2.txt", "r", stdin);
  freopen("./result.txt", "w", stdout);
    
  solve();

  fclose(stdin);
  fclose(stdout);
  return 0;
}
