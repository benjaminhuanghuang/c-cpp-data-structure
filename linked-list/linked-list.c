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
void Insert(struct Node ** head, int x){
  struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = x;
  // temp->next = NULL;
  // if(head != NULL){
  //   temp -> next = head;
  // }
  temp->next = *head;
  *head = temp;
}

void Print(struct Node *head) {
  struct Node *curr = head;
  while(curr != NULL){
    printf(" %d", curr->data);
    curr = curr->next;
  }
}

void Delete(struct Node *head, int n) {
  struct Node *tmp1 = head;
  if(n ==1) {
    head = tmp1->next;
    free(tmp1);
    return;
  }
  
  for(int i =0; i< n-2; i++){
    tmp1 = tmp1->next;
  }
  // tmp1 points to(n-1)th node
  struct Node *tmp2 = tmp1->next;
  tmp1->next = tmp2->next;
  free(tmp2);
}

void Reserve(struct Node **head) {
  struct Node *current, *prev, *next;

  current = *head;
  prev = NULL;

  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

void Reverse(struct Node **head) {
  struct Node *current, *prev, *next;

  current = *head;
  prev = NULL;

  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}


void ReverseRecusion(struct Node *p)
{
  if(p->next == NULL)
  {
    head = p;
    return;
  } 
  Reverse(p->next); 

  struct Node *q = p->next;
  q->next = p;
  p->next = null;
}

int main()
{
  struct Node *head = NULL;

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

  printf("\n");
}