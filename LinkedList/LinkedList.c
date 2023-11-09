#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int val;
  struct Node * nextNode;
} Node;


int main() {
  Node *head = (Node *)malloc(sizeof(Node));
  int n;
  scanf("%d", &n);
  if(!n) return 0;

  Node *current = head;
  current -> val = 1;
  for(int i = 2; i <= n; i++) {
    current -> nextNode = (Node *)malloc(sizeof(Node));
    current = current -> nextNode;
    current -> val = i;
  }

  for(; head; head = head -> nextNode) {
    printf("%d\n", head -> val);
  }
  return 0;
}
