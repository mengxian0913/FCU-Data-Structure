/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 12/22 13:30:28 2023
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

struct node {
  int data;
  int level;
  node *llink, *rlink;
  node() {
    llink=NULL;
    rlink=NULL;
  }
};
struct BS_tree {
  node *head = NULL;
  int level = 0;
  BS_tree(const char *filename);
  void Insert(int num); //包含建立以及插入節點。
  void Delete(int num); //從Binary Search Tree中刪除一個節點。
  void ShowTree(); //以樹狀圖形將此Binary Search Tree印出。
  node* Search(int num); //當呼叫此函數時，傳入一個欲搜尋的數值進行搜尋，
  //若找到則傳回此節點的父親節點，
  //若沒有找到則回傳NULL。
  void LevelTraversal();
  void printSpace(int);
  void Level(node*, int);
};

void BS_tree::Level(node *now, int nowLevel) {
  if(now->llink == NULL && now -> rlink == NULL) {
    level = nowLevel;
    return;
  }

  if(now->llink != NULL) {
    Level(now -> llink, nowLevel + 1);
  }

  if(now -> rlink != NULL) {
    Level(now -> rlink, nowLevel + 1);
  }

  return;
}


void BS_tree::ShowTree() {
  Level(head, 1);
  
  queue<node*> q;
  q.push(head);
  bool endll = true;
  int cnt = 0, space = level;
  
  while(!q.empty()) {
    for(int i = 0; i < (int)(pow(2, space)); i++) {
      cout << " ";
    }

    endll = true;
    int curCnt = pow(2, cnt);
    for(int i = 0; i < curCnt; i++) {
      node *curNode = q.front();
      q.pop();
      if(curNode != NULL) {
        endll = false;
        cout << curNode -> data;
        for(int j = 0; j < (int)(pow(2, space)) - 1; j++) {
          cout << " ";
        }
        for(int j = 0; j < (int)(pow(2, space)); j++) {
          cout << " ";
        }

        q.push(curNode -> llink);
        q.push(curNode -> rlink);
      }

      else {
        cout << " ";
        for(int j = 0; j < (int)(pow(2, space)) - 1; j++) {
          cout << " ";
        }
        for(int j = 0; j < (int)(pow(2, space)); j++) {
          cout << " ";
        }
        q.push(NULL);
        q.push(NULL);
      }
    }
    cout << "\n";
    cnt++;
    space--;

    if(endll) {
      break;
    }
  }

  return;
}


void dfs(node* curNode, int num) {
  if(num >= curNode -> data) {
    if(curNode -> rlink == NULL) {
      curNode -> rlink = new node();
      curNode -> rlink -> data = num;
    } 
    
    else {
      dfs(curNode -> rlink, num);
    }
  }

  else {
    if(curNode -> llink == NULL) {
      curNode -> llink = new node();
      curNode -> llink -> data = num;
    }
    
    else {
      dfs(curNode -> llink, num);
    }
  }
  return;
}

void BS_tree::Insert(int num) {
  if(head == NULL) {
    head = new node();
    head -> data = num;
    return;
  }

  dfs(head, num);
}

BS_tree::BS_tree(const char *filename) {
  ifstream ifs(filename, ifstream::in);
  int num;
  while(ifs >> num) {
    Insert(num);
  }
}


void solve(){
  BS_tree tree("./a.txt");
  tree.ShowTree();
  int num;
  while(1) {
    cout << "Insert Data: ";
    cin >> num;
    tree.Insert(num);
    tree.ShowTree();

  }
}

signed main(){
  // fastIO
  solve();
  return 0;
}
