#define _CRT_SECURE_NO_WARNINGS 
//scanf 오류 방지

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
    *head = temp; //head 포인터가 temp가 됨. [0|] 이게 헤드가 됨.
    return;
}

while(p)
{if (p->data == target){
    if(pp) //이전 노드 존재 시 
    { temp->link=p; //temp다음이 p? temp다음이 p가 되고 
    pp->link = temp;} //pp가 temp를 가르키도록 함.  pp->temp->p. 이러한 방식으로 연결 리스트에 새로운 노드를 중간에 삽입할 수 있습니다.

    else{ //이전 노드가 없는 경우 
        temp->link = *head; //새 노드인 temp[1|]가 head[0|]을 가르키도록 함 .새 노드(temp)의 link 필드를 사용하여 연결 리스트의 현재 첫 번째 노드를 가리키도록 합니다. 즉, 새 노드가 기존의 첫 번째 노드를 '다음 노드'로서 가리키게 되는 것입니다.
        *head = temp; // temp[1|]에서 head[1|]로 변경 : [1|]->[0|] *head에 temp가 가리키는 주소가 저장됩니다.

    }return;

} 
pp = p ; //현재 노드를 이전 노드로 지정 (업뎃) -1
p = p->link; //다음 노드로 탐색 포인터 이동 (pp)p->[new] -2

}
pp ->link = temp; // 리스트 탐색 도중 특정 조건을 만족하는 노드를 찾지 못했을 때 (while 루프를 탈출하여 p == NULL이 된 상황), 새 노드를 리스트의 마지막으로 추가하는 역할을 합니다. 이 과정을 통해, 연결 리스트에 새 노드를 중간이나 마지막 위치에 안전하게 삽입하는 방식. [pp] -> [temp] -> [p] -> ... 나머지 노드들(있다면) ...
}


void addNode(NODE ** head, int data ){
NODE *p = *head; //p포인터에 이중 포인터 head의 역참조값 (일중포인터로서의 head값) 매칭 head포인터가 가르키는 값을 
NODE *temp =(NODE*)malloc(sizeof(NODE));
temp ->data=data; //temp 가 가르키는 구조체의 data에 매개변수로 사용자 입력받은 data 값을 매칭
temp->link=NULL;

if(*head==NULL)
{*head=temp;
return; }

while (p->link) //temp로 이동 
{p=p->link;} //링크타고 다음 노드로 이동. NULL 전까지.
p->link = temp; //p가 NULL 대신 temp를 가르키도록 해 연결. 노드의 맨 끝에 temp를 추가하는 방식. 
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


/*이 코드는 연결 리스트에 정수 데이터를 갖는 노드를 추가하고, 특정 데이터 값을 가진 노드 앞에 새로운 노드를 삽입하는 기능을 포함하고 있습니다. 주어진 main 함수에서는 0부터 5까지의 정수를 갖는 노드들을 순서대로 추가한 다음, 값 '6'을 갖는 노드를 데이터 값 '7'을 갖는 노드 앞에 삽입하려 시도합니다. 데이터 값 '7'을 가진 노드가 리스트에 존재하지 않으므로, 새 노드는 리스트의 끝에 추가될 것입니다.

예상 출력값:

0->1->2->3->4->5
0->1->2->3->4->5->6
*/