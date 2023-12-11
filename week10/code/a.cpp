/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 12/ 1 13:29:33 2023
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
#define MAXN 12

struct node {
  int data;
  node* link;
};

struct equivalence {
  node* seq[MAXN];
  void eqRead(const char*);
  void add(int, int);
  void ShowList();
  void ShowClass();
  void dfs(int);

  equivalence() {
    for(int i = 0; i < MAXN; i++) {
      seq[i] = NULL;
    }
  }
};

bool vis[MAXN];
set<int> ms;

void equivalence::dfs(int now) {
  node *cur = seq[now];
  while(cur != NULL) {
    if(!vis[cur -> data]) {
      vis[cur -> data] = true;
      ms.insert(cur -> data);
      dfs(cur -> data);
    }
    cur = cur -> link;
  }
  return;
}

void equivalence::ShowClass() {
  for(int i = 0; i < MAXN; i++) {
    ms.clear();
    if(!vis[i]) {
      vis[i] = true;
      ms.insert(i);
      dfs(i);
    }
    if(ms.empty()) {
      continue;
    }
    cout << "< ";
    for(auto i : ms) {
      cout << i << ", ";
    }
    cout << "\b\b >\n";
  }
}

void equivalence::ShowList() {
  node *temp;
  for(int i = 0; i < MAXN; i++) {
    printf("seq[%2lld] -> ", i);
    temp = seq[i];
    while(temp != NULL) {
      printf("%lld -> ", temp -> data);
      temp = temp -> link;
    }
    printf("NULL\n");
  }
}

void equivalence::eqRead(const char *fileName) {
  ifstream ifs(fileName, ifstream::in);
  int a, b;
  while(ifs >> a >> b) {
    add(a, b);
  }
  return;
}

void equivalence::add(int a, int b) {
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp -> data = b;
  temp -> link = seq[a];
  seq[a] = temp;
  
  node *temp2;
  temp2 = (node *)malloc(sizeof(node));
  temp2 -> data = a;
  temp2 -> link = seq[b];
  seq[b] = temp2;
  return;
}

void solve(){
  equivalence eq1;
  eq1.eqRead("./a.txt");
  eq1.ShowList();
  eq1.ShowClass();
}

signed main(){
  fastIO
  solve();
  return 0;
}
