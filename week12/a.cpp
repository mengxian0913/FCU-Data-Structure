/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 12/15 13:32:14 2023
*********************************************************/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cstdlib> // for system
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
  void AdjTopDown(int);
  void AdjustHeap(int);
} tree("./a.txt", -1);


void HeapTree::AdjTopDown(int curIndex) {
  int child1 = (curIndex + 1);
  int child2 = (curIndex + 2);

  if(mode == 1) {
    if(child1 <= count && child2 <= count) {
      if(data[child1] < data[child2]) {
        if(data[curIndex] > data[child1]) {
          swap(data[child1], data[curIndex]);
          AdjTopDown(child1);
        }
      }

      else {
        if(data[curIndex] > data[child2]) {
          swap(data[child2], data[curIndex]);
          AdjTopDown(child2);
        }
      }
    }

    else if(child1 <= count && child2 > count && data[curIndex] > data[child1]) {
      swap(data[curIndex], data[child1]);
      AdjTopDown(child1);
    }

    else if(child2 <= count && child1 > count && data[curIndex] > data[child2]) {
      swap(data[curIndex], data[child2]);
      AdjTopDown(child2);
    }

  }

  else {
    if(child1 <= count && child2 <= count) {
      if(data[child1] > data[child2]) {
        if(data[curIndex] < data[child1]) {
          swap(data[child1], data[curIndex]);
          AdjTopDown(child1);
        }
      }

      else {
        if(data[curIndex] < data[child2]) {
          swap(data[child2], data[curIndex]);
          AdjTopDown(child2);
        }
      }
    }

    else if(child1 <= count && child2 > count && data[curIndex] < data[child1]) {
      swap(data[curIndex], data[child1]);
      AdjTopDown(child1);
    }

    else if(child2 <= count && child1 > count && data[curIndex] < data[child2]) {
      swap(data[curIndex], data[child2]);
      AdjTopDown(child2);
    }

  }
  return;
}


void HeapTree::HeapSort() {
  int curCount = count;
  count--;
  while(count >= 0) {
    swap(data[0], data[count--]);
    AdjTopDown(0);
  }
  count = curCount;
  return;
}

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
  
  if(mode == 1) swap(numChild, numParent);

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

  cout << "\n\n";
  return;
}

int HeapTree::GetLevel() {
  int level = 0;
  while((int)(pow(2, level)) < count) {
    level++;
  }
  return level;
}


void printSelectList() {
  cout << "選擇清單：\n\n";
  cout << "(1) 讀取 Heap\n\n";
  cout << "(2) 插入 節點\n\n";
  cout << "(3) 印出 HeapSort 後結果\n\n";
  cout << "Your Input: ";
  return;
}

void printMode() {
  cout << "(1) minHeap\n\n";
  cout << "(2) maxHeap\n\n";
  cout << "Your Input: ";
  return;
}


void solve(int mode) {
  
  if(mode == 1) {
    int MinMax = 0;
    printMode();
    cin >> MinMax;
    system("clear");
    if(MinMax != 1 && MinMax != 2) return;
    HeapTree curTree("./a.txt", MinMax); 
    tree = curTree;
    cout << "Tree Level: " << tree.GetLevel() << "\n";
    cout << "HeapTree:\n";
    tree.ShowTree();
  }


  else if(mode == 2) {
    if(tree.mode == -1) {
      cout << "請先選擇 Heap 規則\n";
      return;
    }
    int insertNumber;
    cout << "Enter the number: ";
    cin >> insertNumber;
    system("clear");
    tree.InsertData(insertNumber);
    cout << "Tree Level: " << tree.GetLevel() << "\n";
    cout << "HeapTree:\n";
    tree.ShowTree();
  }


  else if(mode == 3) {
    if(tree.mode == -1) {
      cout << "請先選擇 Heap 規則\n";
      return;
    }
    cout << "Sorted HeapTree: \n";
    tree.HeapSort();
    tree.ShowTree();
  }

  return;
}

signed main(){
  int mode;
  char modeC;
  do {
    printSelectList();
    cin >> modeC;
    mode = modeC - '0';
    system("clear");
    solve(mode);
  } while(true);
  return 0;
}
