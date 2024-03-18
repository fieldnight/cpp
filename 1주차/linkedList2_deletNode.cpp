#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
   int data;
   struct node *link;
}NODE;

void deleteNode(NODE **head , int data){

NODE *p = *head, *pp = NULL;
while(p){
    if(p->data == data){
        if(pp)
        pp->link = p->link;
        else
        *head = p->link;
        free(p);
        return;
    }
    pp=p;
    p=p->link
}
}