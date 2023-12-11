/*********************************************************
# File Name: a.c
# Author: Vincent
# Mail: mengxian0913@gmail.com
# Created Time: 四 12/ 7 11:27:34 2023
*********************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node* nodePtr;

typedef struct Node {
  int data;
  nodePtr link;
} Node;


void solve(nodePtr *head, nodePtr *rear) {
  int n;
  scanf("%d", &n);
  
  nodePtr newNode = (nodePtr)malloc(sizeof(Node));
  newNode -> data = n;
  newNode -> link = NULL;

  if(*head == *rear && *rear == NULL) {
    *rear = newNode;
    *head = *rear;
  } else {
    (*rear) -> link = newNode;
    (*rear) = (*rear) -> link;
  }
  return;
}


int main() {
  Node *head = NULL;
  Node *rear = head;
  int t;
  scanf("%d", &t);
  while(t--) {
    solve(&head, &rear);
  }

  while(head != NULL) {
    printf("%p\t%d\n", &head, head -> data);
    head = head -> link;
  }
  return 0;
}
