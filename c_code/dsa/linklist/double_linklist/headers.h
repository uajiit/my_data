struct node
{

struct node *prev;
int info;
struct node *next; 
};


void display(struct node *start);

struct node *create(struct node *start);

struct node *addatend(struct node *start);

void rev_linklist_display(struct node *start);
