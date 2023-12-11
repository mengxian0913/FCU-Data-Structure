#include<bits/stdc++.h>
using namespace std;

#define int long long


struct Node {
  int val;
  Node *nxt = NULL;
};

void invert(Node *head) {
  Node *cur = head;
  Node *prevNode = NULL;
  Node *nxtNode = NULL;

  while(cur) {
    nxtNode = cur -> nxt;
    cur -> nxt = prevNode;
    prevNode = cur;
    cur = nxtNode;
  }

  head = prevNode;

  while(head) {
    cout << head -> val << " -> ";
    head = head -> nxt;
  }
  cout << "\b\b\b   \n";
  return;
}

signed main() {
  Node *head = (Node*)malloc(sizeof(Node));
  Node *current = head;

  int n;
  cin >> n;


  if(n == 0) {
    return 0;
  }

  current -> val = 1;
  
  for(int i = 2; i <= n; i++) {
    current -> nxt = (Node*)malloc(sizeof(Node));
    current = current -> nxt;
    current -> val = i;
  }

  Node *temp = head;

  while(head != NULL) {
    // cout << "Val: " << head -> val << " Pointer: " << head -> nxt << "\n";
    cout << head -> val << " -> ";
    head = head -> nxt;
  }
  cout << "\b\b\b\b    \n";


  invert(temp);

  return 0;
}
