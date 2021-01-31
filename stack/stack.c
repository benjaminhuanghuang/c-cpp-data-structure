#include <stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int x)
{
  if (top == MAX_SIZE - 1)
  {
    printf("Error. ");
    return;
  }
  A[++top] = x;
}

void pop()
{
  if (top == -1)
  {
    printf("Error\n");
    return;
  }
  top--;
}

int Top(){
  return A[top];
}

int main() {

}