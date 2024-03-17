#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

int data;
struct node *link;

}NODE;

int main (){

NODE*head = NULL, *p=NULL, *temp=NULL;
int i;
for(i=0; i<4; i++){

    temp =(NODE*)malloc(sizeof(NODE));
    temp->data=i;
    temp->link=NULL;

    if(head==NULL)
    {head= temp;}   
    else{p->link=temp;}
    p=temp; 
}

    p=head; //결국 p=0
    while(p){
        printf("%d%s",p->data,p->link ?"->":"");
        p=p->link;
    }
}//결과 0->1->2->3