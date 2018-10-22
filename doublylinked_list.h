struct node* create_head();
struct node* create_node();
void insert_first(struct node* head,int data);
void insert_last(struct node* head,int data);
void insert_after(struct node* head,struct node* key,int data);
void insert_before(struct node* head,struct node* key,int data);
void delete_first(struct node* head);
void delete_last(struct node* head);
void traversal(struct node* head);
