/*
   Thomas Cross
   linked list program
*/

#include<stdio.h>
#include<stdlib.h>
#include "srec.h"


struct Node {
    struct Srec *data;
    struct Node *prev;
    struct Node *next;
};

struct Node *newNode(void);
void initNode(struct Node *);
int length(struct Node *);
void push(struct Node **);
void insertNode(struct Node **, struct Srec *, int);
void printList(struct Node *);
int compSrec(struct Srec *, struct Srec *, int);
void freeList(struct Node *);

int main(void)
{
    struct Node *lname_list_head = NULL;
    printf("%d\n", length(lname_list_head));
    struct Srec *s1 = newSrec();
    struct Srec *s2 = newSrec();
    struct Srec *s3 = newSrec();
    setSrec(s1, "Cross\n", 'D', "Thomas\n", 11337, 3.006);
    setSrec(s2, "Larson\n", 'E', "Kirk\n", 45698, 4.0);
    setSrec(s3, "Mantz\n", 'N', "Erin\n", 48956, 3.8);

    insertNode(&lname_list_head, s1, gpa_cmp);
    insertNode(&lname_list_head, s2, gpa_cmp);
    insertNode(&lname_list_head, s3, gpa_cmp);

    printf("%d\n", length(lname_list_head));
    
    printList(lname_list_head);
    freeList(lname_list_head);
    return 0;
}

/*
    Can you initialize node pointer in the struct?! 
    Initialization list error.
    ...Yes the same way you initialize an array.
*/
struct Node *newNode()
{
    struct Node *node = (struct Node *)malloc(1 * sizeof(struct Node));
    initNode(node);
    return node;
}

void initNode(struct Node *node)
{
    /*node->data = (struct Srec *)malloc(1 * sizeof(struct Srec));*/
    /*initSrec(node->data);*/
    node->next = NULL;
    node->prev = NULL;
}

int length(struct Node *head)
{
    int count = 0;
    struct Node *curr = head;
    while(curr != NULL)
    {
        ++count;
        curr = curr->next;
    }
    return count;
}

/*
    Pass address of head.
    1)Make a new node called node
    2)Link nodes' next, to head.  It is the head now.
    3)Make the new node the head(Begining) of the list.
*/
void push(struct Node **head)
{
    struct Node *node = newNode();
    node->next = *head;
    *head = node;
}

void printList(struct Node *head)
{
    struct Node *curr = head;
    while(curr != NULL)
    {
        printSrec(curr->data);
        curr = curr->next;
    }
}

void insertNode(struct Node **head, struct Srec *srec, int sort_by)
{
    struct Node *new_node = newNode();
    new_node->data = srec;


    if(*head == NULL || comp((*head)->data, srec, sort_by) > 0)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        struct Node *prev = *head;
        while(prev->next != NULL && comp(prev->next->data, srec, sort_by) < 0)
        {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
}

/*
    Takes a Node pointer and returns strcmp value. 
*/
int comp(struct Srec *a, struct Srec *b, int cmp_type)
{
    int rval = -1;
    switch(cmp_type)
    {
        case lname_cmp:
        {
            rval = strcmp(a->lname, b->lname);
            break;
        }
        case fname_cmp:
        {
            rval = strcmp(a->fname, b->fname);
            break;
        }
        case sid_cmp:
        {
            rval = ((a->sid > b->sid) ? 1:-1);
            break;
        }
        case gpa_cmp:
        {
            rval = ((a->gpa < b->gpa) ? 1:-1);
            break;
        }
        default:
        {
            break;
        }
    }
    return rval;
}

void freeList(struct Node *head)
{
    struct Node *curr = head;
    struct Node *temp = head;
    while(curr != NULL)
    {
        temp = curr->next;
        free(curr->data);
        free(curr);
        curr = temp;
    }
}
