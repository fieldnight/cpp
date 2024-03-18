#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node

{
    char code[20];
    char name[10];

    int kor, eng, math;

    struct node* link;
}STUDENT;

void insertStudent(STUDENT** head, char* name, char* code, int kor, int eng, int math) {
    STUDENT* p = *head, * pp = NULL;

    STUDENT* temp = (STUDENT*)malloc(sizeof(STUDENT));

    strcpy(temp->name, name);	strcpy(temp->code, code);

    temp->kor = kor;		temp->eng = eng;		temp->math = math;	temp->link = NULL;

    if (*head == NULL) { //리스트가 비었는 경우

        *head = temp;

        return;

    }

    while (p) {

        if (strcmp(p->code, temp->code) > 0) { //삽입할 위치를 찾은경우(temp의 학번보다 큰 학번을 찾은경우)

            if (pp) pp->link = temp;  //삽입코드

            else *head = temp;

            temp->link = p;

            return;

        }

        pp = p;
        p = p->link;

    }

    pp->link = temp; //삽입할 위치를 못찾은 경우 -> temp는 가장뒤에 붙어야함.

}



void showStudent(STUDENT* head)

{
    STUDENT* p = head;
    while (p)

    {
        printf("%s\t%s\t%d\t%d\t%d\n", p->code, p->name, p->kor, p->eng, p->math);
        p = p->link;
    }
    printf("\n");
}


void deleteStudent(STUDENT** head, char name[10]) {
    STUDENT* p = *head, * pp = NULL;
    while (p) {
        if (strcmp(p->name, name) == 0) {
            if (pp)
                pp->link = p->link;
            else
                *head = p->link;
            free(p);
            return;
        }
        pp = p;
        p = p->link;
    }
}


void freeStudentAll(STUDENT* head) {
    STUDENT* p = head, * pp = NULL;

    while (p) {

        free(p);
        p = pp;
        p = p->link;
    }
}



int main()
{
    STUDENT* head = NULL;

    int sel = 0;
    char name[10], code[10];
    int kor, eng, math;

    while (sel != 4) {

        printf("\n1. 입력 2. 출력 3. 삭제 4. 종료 \n선택하세요: ");
        scanf("%d", &sel);

        switch (sel)
        {
        case 1:
            printf("이름:"); scanf("%s", name);
            printf("학번:"); scanf("%s", code);
            printf("국어:"); scanf("%d", &kor);
            printf("영어:"); scanf("%d", &eng);
            printf("수학:"); scanf("%d", &math);
            insertStudent(&head, name, code, kor, eng, math);
            printf("-----학생정보가 입력되었습니다.----\n");
            break;

        case 2:
            showStudent(head);
            printf("----학생 정보가 출력되었습니다.----\n");
            break;

        case 3:
            printf("정보를 삭제할 학생의 이름을 작성하세요: ");
            scanf("%s", name);
            deleteStudent(&head, name);
            printf(" ----학생 %s의 정보가 삭제되었습니다.----\n", name);
            break;

        case 4:
            freeStudentAll(head);
            printf("----프로그램이 종료되었습니다.----\n");
            break;

        default:
            printf("----보기 중에서 선택해주세요.----");
            break;
        }
    }

    return 0;