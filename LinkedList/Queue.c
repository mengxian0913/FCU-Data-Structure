// queue
#include<stdio.h>
#include<stdlib.h>

typedef struct Node* NodePtr;

typedef struct Node{
  int val;
  NodePtr nextNode;
}Node;

void solve(NodePtr *Front, NodePtr *Rear) {
  int method;
  printf("enter the method (1) push a value in rear of queue | (2) pop a value in front of queue: ");
  scanf("%d", &method);

  if(method == 1) {
    int value;
    printf("Enter the value to push the rear of the queue: ");
    scanf("%d", &value);
    NodePtr NewNode = (NodePtr)malloc(sizeof(Node));
    NewNode -> val = value;
    NewNode -> nextNode = NULL;
    if(*Front == *Rear && *Front == NULL) {
      *Rear = NewNode;  
      *Front = *Rear;
    } else {
      (*Rear) -> nextNode = NewNode;
      (*Rear) = (*Rear) -> nextNode;
    }
    
  } else {
    if((*Front) == NULL) {
      printf("The queue is Empty!\n");
      return;
    }
    int topValue = (*Front) -> val;
    NodePtr cur = *Front;
    *Front = (*Front) -> nextNode;
    free(cur);
    printf("Top value of queue: %d\n", topValue);
  }
  
  return;
}

int main() {
  NodePtr Front = NULL;
  NodePtr Rear = Front;
  int t;
  printf("Enter the number of operations: ");
  scanf("%d", &t);

  while(t--) {
    solve(&Front, &Rear);
  }
  
  printf("Print the result of the queue\n");

  if(Front == NULL) {
    printf("The queue is Empty!\n");
    return 0;
  }

  for(; Front != NULL; Front = Front -> nextNode) {
    printf("Val: %d, nextPointer: %p\n", Front -> val, Front -> nextNode);
  }

  return 0;
}
