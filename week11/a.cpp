/*********************************************************
# File Name: a.cpp
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 五 12/ 8 13:20:35 2023
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

struct Node {
  int data;
  Node* llink;
  Node* rlink;
  Node(char c) {
    data = c;
    llink=NULL;
    rlink=NULL;
  }
};

struct Tree {
  Node* root;
  int height = 1;
  Tree(const char *filename);
  void LevelTraversal();//掃描每一層 node 的內容並輸出
  void inorder(Node *tmp);//中序
  void postorder(Node *tmp);//前序
  void preorder(Node *tmp);//後序
};


void Tree::inorder(Node *tmp) {
  if (tmp != NULL) {
    inorder(tmp->llink);
    cout << tmp->data << " ";
    inorder(tmp->rlink);
  }
}

void Tree::preorder(Node *tmp) {
  if (tmp != NULL) {
    cout << tmp->data << " ";
    preorder(tmp->llink);
    preorder(tmp->rlink);
  }
}

void Tree::postorder(Node *tmp) {
  if (tmp != NULL) {
    postorder(tmp->llink);
    postorder(tmp->rlink);
    cout << tmp->data << " ";
  }
}


void Tree::LevelTraversal() {
  queue<Node*> qu;
  qu.push(root);
  int index = 1, preSpace = height, midSpace = height;

  while(!qu.empty() && qu.front() != NULL) {

    for(int i = 0; i < (int)(pow(2, preSpace)); i++) {
      cout << " ";
    }

    for(int i = 0; i < index && !qu.empty(); i++) {
      Node *curNode = qu.front();
      qu.push(curNode -> llink);
      qu.push(curNode -> rlink);
      qu.pop();
      cout << curNode -> data;
      for(int j = 0; j < (int)(pow(2, midSpace)) - 1; j++) {
        cout << " ";
      }
      for(int j = 0; j < (int)(pow(2, midSpace)); j++) {
        cout << " ";
      }

    }
    cout << "\n";
    index <<= 1;
    preSpace --;
    midSpace--;
  }
  return;
}


Tree::Tree(const char *filename) {
  ifstream ifs(filename, ifstream::in);
  vector<int>myNode(31);
  for(int i = 0; i < 32; i++) {
    myNode[i] = i;
  }
  // ifs >> myNode;

  queue<Node*>quptr;
  root = (Node*)malloc(sizeof(Node));
  root ->data =  myNode[0];
  quptr.push(root);


  for(int i = 1; i < myNode.size(); i+=2) {
    int node1 = myNode[i], node2 = myNode[i + 1];
    Node *fatherNode = quptr.front();
    quptr.pop();

    Node *newNode1 = new Node(node1);
    Node *newNode2 = new Node(node2);

    fatherNode -> llink = newNode1;
    fatherNode -> rlink = newNode2;

    quptr.push(newNode1);
    quptr.push(newNode2);
  }


  int sz = quptr.size();
  while(sz > 1) {
    height++;
    sz >>= 1;
  }
}


void solve(){
  Tree tree("./a.txt");
  cout << "Tree height: " << tree.height << "\n";
  tree.LevelTraversal();
  cout << "\n";
  cout << "Inorder: ";
  tree.inorder(tree.root);
  cout << "\n";
  cout << "Preorder: ";
  tree.preorder(tree.root);
  cout << "\n";
  cout << "Postorder: ";
  tree.postorder(tree.root);
}

signed main(){
  fastIO
  solve();
  return 0;
}
