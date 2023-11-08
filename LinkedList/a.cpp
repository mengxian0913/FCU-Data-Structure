#include<bits/stdc++.h>
using namespace std;

#define int long long


struct Node {
  int val;
  Node *nxt = NULL;
};



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

  while(head != NULL) {
    cout << "Val: " << head -> val << " Pointer: " << head -> nxt << "\n";
    head = head -> nxt;
  }

  return 0;
}
