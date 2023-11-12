/// stack
#include<stdio.h>
#include<stdlib.h>

typedef struct Node * NodePtr;

typedef struct Node {
  int val;
  NodePtr next; // Node *
} Node;

void push(NodePtr *head, int val) {
  NodePtr newNode = (NodePtr)malloc(sizeof(Node));
  newNode -> val = val;
  newNode -> next = (*head);
  *head = newNode;
  return;
}

void pop(NodePtr *head) {
  if(*head == NULL) {
    printf("The Stack is Empty!\n");
  } else {
    int topValue = (*head) -> val;
    printf("The top value of the stack: %d\n", topValue);
    NodePtr cur = *head;
    *head = (*head) -> next;
    free(cur);
  }
  return;
}

int main() {
  NodePtr head = NULL;

  push(&head, 20);
  push(&head, 30);
  pop(&head);

  while(head != NULL) {
    printf("Val: %d, nextPointer: %p\n", head -> val, head -> next);
    head = head -> next;
  }
  return 0;
}
