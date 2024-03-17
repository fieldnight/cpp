#include <stdio.h>  //#define NULL((void*)0) => 마지막 노드의 링크가 :NULL 일떄  값이 0으로 설정됨. 
#include <stdlib.h> 
#include <string.h>

typedef struct node {
    int data; 
    struct node *link;
}NODE;

//typedef ~ NODE: 기존 정해진 타입에 간단한 이름 부여로 가독성 증가, 구조체 s.n.에 NODE 라는 이름 부여.  

int main(){
    NODE * head = NULL, *p = NULL , *temp=NULL; // 할당 없이 포인터 선언하면 임의의 메모리를 가르키므로, 임시방편으로 NULL을 할당

    int i; 
    for(i=0; i<4; i++){
        temp = (NODE*)malloc(sizeof(NODE)); //구조체형식의 데이터를 담을 동적메모리를 할당, 구조체 타입의 포인터를 리턴해서 temp 에 매칭.  
        temp->data=i;
        temp->link=NULL;
        //data는 i며 (0,1,2,3) 포인터는 NULL인 노드 생성 

        if(head!=NULL){
            temp->link=head;
        } //일단은 head가 NULL이니 지나치다가
        head=temp; //헤드에 0,1,2,3의 포인터를 매칭한다. 
    }

p=head; //for문을 벗어난 뒤 최종 헤드는 3
while(p){
    printf("%d%s", p->data, p->link ?"->" :""); 
    //(1과 2의 자료형,출력할 내용1:data,출력할 내용2:삼항연산자)
    p=p->link;
}
} //결과 3->2->1->0