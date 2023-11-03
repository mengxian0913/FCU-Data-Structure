/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 11/ 3 13:19:35 2023
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

#define MAXN 1010

struct MyStack {
  int top;
  char a[MAXN];
  bool IsEmpty();
  bool IsFull();
  void Push(char);
  char Pop();
  MyStack() {
    top = -1;
  }
};

bool MyStack::IsEmpty() {
  return (top == -1);
}

bool MyStack::IsFull() {
  return (top == MAXN - 1);
}

void MyStack::Push(char ch) {
  if(IsFull()) {
    cout << "The Stack is Full!\n";
    return;
  }
  a[++top] = ch;
  return;
}

char MyStack::Pop() {
  if(IsEmpty()){
    cout << "The Stack is Empty!\n";
    return ' ';
  }
  return a[top--];
}


void solve(){
  MyStack S;
  string ss;
  while(cin >> ss) {
    for(int i = 0; i < ss.size(); i++) {
            
    }
  }

  return;
}

signed main(){
  fastIO
  solve();
  return 0;
}
