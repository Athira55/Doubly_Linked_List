#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
   int value;
   struct Node* next;
   struct Node* prev;
}node;
node* create_head(){
   node* head;
   head=malloc(sizeof(node));
   head->prev = NULL;
   head->next = NULL;
   return head;
}
node* create_node(){
  node* newnode;
  newnode = malloc(sizeof(node));
  return newnode;
}
void insert_first(node* head,int data){
  node* newnode;
  newnode=create_node();
  newnode->value = data;
  if (head->next== NULL) {
     head->next = &newnode;
     newnode->prev = &head;
     newnode->next = NULL;
  }
  else{
     newnode->next = head->next;
     (head->next)->prev = &newnode;
     head->next=&newnode;
     newnode->prev = &head;
     newnode->next= NULL;
  }

}
void insert_last(node* head,int data) {
  node* current;
  node* newnode;
  newnode = create_node();
  newnode->value=data;
  if(head->next == NULL){
    head-> next = &newnode;
    newnode->next = NULL;
  }
  else{
    current=head->next;
    while (current->next != NULL)
      current = current->next;
    current->next = &newnode;
    newnode->next = NULL;

  }
}
void insert_after(node* head,node* key,int data){
  int flag;
  node* current;
  node* newnode;
  newnode = create_node();
  newnode->value = data;
  current = head->next;
  flag=1;
  while (current!=NULL) {
    if (current != key) {
      current=current->next;
    }
    else{
      flag=2;
      break;
    }
  }
  if (flag==2) {
      (current->next)->prev = &newnode;
      newnode->next = current-> next;
      newnode->prev = &current;
      current->next = &newnode;
  }
  else
      printf("key not found");
}
void insert_before(node* head,node* key,int data){
  int flag;
  node* current;
  node* newnode;
  newnode = create_node();
  newnode->value = data;
  current = head->next;
  flag=1;
  while (current!=NULL) {
    if (current != key) {
      current=current->next;
    }
    else{
      flag=2;
      break;
    }
  }
  if (flag==2) {
      (current->prev)->next = &newnode;
      newnode->prev = current->prev;
      newnode->next = &current;
      current->prev = &newnode;
  }
  else
      printf("key not found");
}
void delete_first(node* head) {
  if(head->next==NULL)
    printf("List is empty");
  head->next = (head->next)->next;
}
void delete_last(node* head){
  node* current;
  current=head->next;
  if(head->next==NULL)
    printf("List is empty");
  else{
    while (current->next!=NULL) {
      current=current->next;
      (current->prev)->next=NULL;
    }
  }
}
void traversal(node* head){
  node* current=head->next;
  if(head->next==NULL)
    printf("List is empty");
  while (current!=NULL) {
    printf(current->value);
    current=current->next;
  }
}
