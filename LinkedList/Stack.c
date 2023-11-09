// stack
#include<stdio.h>
#include<stdlib.h>

typedef struct Node * NodePtr;

typedef struct Node {
  int val;
  NodePtr next; // Node *
} Node;

void solve(NodePtr * head) {
  int method;
  printf("Enter the method (1) push the value | (2) pop the value: ");
  scanf("%d", &method);

  if(method == 1) {
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);

    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode -> val = val;
    newNode -> next = (*head);
    *head = newNode;   
  }

  else {
    if(*head == NULL) {
      printf("The Stack is Empty!\n");
    } else {
      int topValue = (*head) -> val;
      printf("The top value of the stack: %d\n", topValue);
      NodePtr cur = *head;
      *head = (*head) -> next;
      free(cur);
    }
  }

  return;
}

int main() {
  NodePtr head = NULL;
  int t;
  printf("Enter the number of operations: ");
  scanf("%d", &t);

  while(t--) {
    solve(&head);
    // printf("NowVal: %d\n", head -> val);
  }

  while(head != NULL) {
    printf("Val: %d, nextPointer: %p\n", head -> val, head -> next);
    head = head -> next;
  }

  return 0;
}
