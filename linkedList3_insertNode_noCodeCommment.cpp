#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>



typedef struct node {

    int data;
    struct  node *link;
}NODE;


void insertNode(NODE **head , int data, int target){

    NODE *p = *head;
    NODE *pp = NULL;
    NODE* temp =(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->link =NULL;


if( *head == NULL){
    *head = temp; 
    return;
}

while(p)
{if (p->data == target){
    if(pp) 
    { temp->link=p; 
    pp->link = temp;}

    else{ 
        temp->link = *head; 
        *head = temp;
    }return;

} 
pp = p ; 
p = p->link; 

}
pp ->link = temp; 
}



void addNode(NODE ** head, int data ){
NODE *p = *head;
NODE *temp =(NODE*)malloc(sizeof(NODE));
temp ->data=data; 
temp->link=NULL;

if(*head==NULL)
{*head=temp;
return; }

while (p->link) 
{p=p->link;} 
p->link = temp; 
};




void showList(NODE *head){
    NODE *p = head;
    while(p){
        printf("%d%s", p->data, p->link ?"->" :"");
        p = p->link;
    }
    printf("\n");
}

void main (){
    NODE * head = NULL;
    for(int i=0; i<6; i++){
        addNode(&head, i);
    }
     showList(head);
     insertNode(&head, 6, 7);
     showList(head);
}


