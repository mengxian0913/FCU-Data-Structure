// stack version 2
#include<stdio.h>
#include<strlib.h>

#define MAXN 10

typedef struct stack * stackPointer;

typedef struct {
  int key;
} element;

typedef struct stack {
  element item;
  stackPointer link;
} stack;

stackPointer top[MAXN];

void add(stackPointer *top, element item) {
  stackPointer temp = (stackPointer)malloc(sizeof(stack));
  temp -> item = item;
  temp -> link = *top;
  *top = temp;
  return;
}


int main() {

}
