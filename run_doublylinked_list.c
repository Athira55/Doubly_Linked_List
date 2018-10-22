#include "doublylinked_list.h"
#include<stdio.h>
#include<stdlib.h>
void main(){

  struct node* head = create_head();
  insert_first(head,10);
  insert_first(head,20);
  traversal(head);

}
