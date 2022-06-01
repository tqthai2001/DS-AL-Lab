typedef struct node{
    int data;
    struct node *link;
}node;

int isEmpty(node *p);
int size(node *p);
node *push(node *p, int value);
node *pop(node *p, int *value);
node *top(node *p, int *value);