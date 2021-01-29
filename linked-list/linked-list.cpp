#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int data;
  struct Node *next;
};

/*
  instert at beginning
*/
void Insert(Node ** head, int x){
  struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = x;
  // temp->next = NULL;
  // if(head != NULL){
  //   temp -> next = head;
  // }
  temp->next = *head;
  *head = temp;
}

void Print(Node *head) {
  struct Node *curr = head;
  while(curr != NULL){
    printf(" %d", curr->data);
    curr = curr->next;
  }
}


int main()
{
  Node *head = NULL;

  printf("How many numberes?\n");
  int n,x;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enteer the nubmer?\n");
    scanf("%d", &x);
    Insert(&head, x);
  }
 
  Print(head);
}