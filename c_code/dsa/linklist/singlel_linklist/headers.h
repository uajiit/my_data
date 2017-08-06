struct node
{
int info;
struct node *link; 
};


void display(struct node *start);

struct node *create(struct node *start);

struct node *addatend(struct node *start);

void rev_linklist_display(struct node *start);
