#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int val;
  struct Node * nextNode;
} Node;


int main() {
    Node a = (Node *) malloc(sizeof(Node));
    a -> data = 1;
    Node b = (Node *) malloc(sizeof(Node));
    b -> data = 2;
    a -> nextNode = b;
    Node c = (Node *) malloc(sizeof(Node));
    c -> data = 3;
    b -> nextNode = c;
    return 0;
}


// int main() {
//   Node *head = (Node *)malloc(sizeof(Node));
//   int n;
//   scanf("%d", &n);
//   if(!n) return 0;
//
//   Node *current = head;
//   current -> val = 1;
//   for(int i = 2; i <= n; i++) {
//     current -> nextNode = (Node *)malloc(sizeof(Node));
//     current = current -> nextNode;
//     current -> val = i;
//   }
//
//   for(; head; head = head -> nextNode) {
//     printf("%d\n", head -> val);
//   }
//   return 0;
// }
