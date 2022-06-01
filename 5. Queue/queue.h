typedef struct Contact{
    char name[30];
    char tel[10];
    char email[35];
}Contact;

typedef struct node{
    Contact data;
    struct node *link;
}node;

typedef struct queue{
    node *front;
    node *rear;
}queue;

int isEmpty(queue *q);
void makeQueue(queue *q);
void enQueue(queue *q, Contact value);
void deQueue(queue *q, Contact *value);
void front(queue *q, Contact *value);