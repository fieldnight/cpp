#include<stdio.h>

#include<stdlib.h>

#include<string.h>

typedef struct student

{

	char name[20];

	char code[10];

	int kor, eng, math;

	struct student* link;

}STUDENT;

void sort_insertNode(STUDENT** h, char * name, char * code, int kor, int eng, int math){

	STUDENT* p = *h, *pp = NULL;

	STUDENT* temp = (STUDENT*)malloc(sizeof(STUDENT));

	strcpy(temp->name, name);	strcpy(temp->code, code);

	temp->kor = kor;		temp->eng = eng;		temp->math = math;	temp->link = NULL;

	if (*h == NULL) 	{ //리스트가 비었는 경우

		*h = temp;

		return;

	}

	while (p)	{

		if (strcmp(p->code, temp->code) > 0) 	{ //삽입할 위치를 찾은경우(temp의 학번보다 큰 학번을 찾은경우)

			if (pp) pp->link = temp;  //삽입코드

			else *h = temp;

			temp->link = p;

			return;

		}

		pp = p;

		p = p->link;

	}

	pp->link = temp; //삽입할 위치를 못찾은 경우 -> temp는 가장뒤에 붙어야함.

}

void show(STUDENT* p)

{

	while (p)

	{

		printf("%s\t%s\t%d\t%d\t%d\n", p->code, p->name, p->kor, p->eng, p->math);

		p = p->link;

	}

}

int main()

{

	STUDENT* h = NULL;

	sort_insertNode(&h, "장용훈", "1010", 100, 90, 50);

	sort_insertNode(&h, "김성호", "1012", 100, 90, 50);

	sort_insertNode(&h, "황상호", "1009", 100, 90, 50);

	show(h);

	return 0;

}