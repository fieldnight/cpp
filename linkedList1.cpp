#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
   int data;
   struct node *link;
}NODE;


void addNode(NODE ** head, int data ){
NODE *p = *head; //p포인터에 이중 포인터 head의 역참조값 (일중포인터로서의 head값) 매칭 head포인터가 가르키는 값을 
NODE *temp =(NODE*)malloc(sizeof(NODE));
temp ->data=data; //temp 가 가르키는 구조체의 data에 매개변수로 사용자 입력받은 data 값을 매칭
temp->link=NULL;

if(*head==NULL)
{*head=temp;
return; }

 /*
 *temp 0일때:  이중포인터 head는 일단 head-> NULL인 상태. p에 해당NULL을 가르키는 head가 매칭됬을 뿐. head가 NULL 대신 temp(0)를 가르키게 됨
 *temp 1,2일때: head 값이 0을 가르키는 temp로 지정됬으니 해당 스코프에 들어가지 않는다.   */


while (p->link) //temp로 이동 
{p=p->link;} //링크타고 다음 노드로 이동. NULL 전까지.
p->link = temp; //p가 NULL 대신 temp를 가르키도록 해 연결. 
};


void showList (NODE * head){
    NODE * p =head;
    while(p){
        printf("%d%s", p->data, p->link?"->":"");
        p=p->link;

    }
    printf("\n");

}

int main (){
    NODE *head=NULL;
    int i;
    for(i=0; i<3; i++){
        addNode(&head, i);
    }
    showList (head);
}

//일중 포인터에 이중 포인터를 넣지 말자. 
