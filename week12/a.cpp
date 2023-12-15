/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 12/15 13:32:14 2023
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

struct HeapTree {
  int data[MAXN];
  int count = 0;
  int mode;
  HeapTree(const char*, const int);
  void InsertData(int);
  void Show();
  void ShowSpace(int);
  int MyPower(int);
  int GetLevel();
  void ShowTree();
  void HeapSort();
  void AdjustHeap(int);
};

HeapTree::HeapTree(const char *file, int md) {
  mode = md;
  ifstream ifs(file, ifstream::in);
  int num;
  while(ifs >> num) {
    InsertData(num);  
  }
}

void HeapTree::InsertData(int num) {
  data[count] = num;
  AdjustHeap(count);
  count++;
}

void HeapTree::AdjustHeap(int curIndex) {
  int numChild = data[curIndex];
  int numParent = data[(curIndex - 1) / 2];
  
  if(mode == 0) swap(numChild, numParent);

  if(numChild > numParent) {
    swap(data[curIndex], data[(curIndex - 1) / 2]);
    AdjustHeap((curIndex - 1) / 2);
  }
  return;
}

void HeapTree::ShowTree() {
  int space = GetLevel() + 1; // adjust the margin of element
  pair<int, int>nowLevel = {1, 1}; // {level, amount} -> amount = pow(2, level - 1)
  for(int i = 0; i < count; i++) {
    if(i + 1 == nowLevel.ss) {
      nowLevel = {nowLevel.ff + 1, (int)pow(2, nowLevel.ff)};
      cout << "\n";
      space -= 1;
      for(int sp = 0; sp < (int)pow(2, space); sp++) cout << " ";

    }

    cout << data[i];
    for(int sp = 0; sp < (int)(pow(2, space)); sp++) {
      cout << " ";
    }

    for(int sp = 0; sp < (int)(pow(2, space)) - 1; sp++) {
      cout << " ";
    }
  }
  return;
}

int HeapTree::GetLevel() {
  int level = 0;
  while((int)(pow(2, level)) < count) {
    level++;
  }
  return level;
}

void solve(){
  int mode;
  cout << "選擇 (0)minHeap | (1)maxHeap: ";
  cin >> mode;
  HeapTree tree("./a.txt", mode);
  cout << "Tree Level: " << tree.GetLevel() << "\n";
  cout << "HeapTree:\n";
  tree.ShowTree();
  cout << "\n\n";

  int insertNumber;
  cout << "insertNumber(0 to end): ";
  cin >> insertNumber;
  while(insertNumber != 0) {
    tree.InsertData(insertNumber);
    tree.ShowTree();
    cout << "\n\n";
    cout << "insertNumber(0 to end): ";
    cin >> insertNumber;
  }
  cout << "Final HeapTree: \n";
  tree.ShowTree();
  return;
}

signed main(){
  // fastIO
  solve();
  return 0;
}
