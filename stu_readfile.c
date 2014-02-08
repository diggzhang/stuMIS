/*
	读入学生信息文件
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stu_main();

stu_node *add_node(stu_node *head);

stu_node *file2node(FILE *fp)
{
	int re;
	stu_node *p=NULL;
	stu_node *head=NULL;
	stu_node *tail=NULL;

	if(fp == NULL)
	{
		printf("学生信息表无法打开\n");
		getchar();
		exit(1);
	}

	while(1)
	{
		p=malloc(sizeof(stu_node));
		if(NULL == p)
		{
			printf("malloc error\n");
			exit(-1);
		}
		p->pre=NULL;
		p->next=NULL;
	
		re = fscanf(fp,"%d %s %s %d %d %d %d %d %d\n",&p->id,p->name,p->passwd,&p->age,&p->in_class,&p->math,&p->clang,&p->yuwen,&p->mingci);

		if(re<0)
			break;
		
		tail=head;
		if(head == NULL)
		{
			head = p;
		}
		else
		{
			while(tail->next != NULL)
				tail=tail->next;
			tail->next = p;
			p->pre =tail;
		}
	}
	fclose(fp);
	return head;
}

void print_link(stu_node *head)
{
	stu_node *p=NULL;
	int mingci=1;
	for(p=head; p!=NULL; p=p->next)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",p->id,p->name,p->age,p->in_class,p->math,p->clang,p->yuwen,mingci++);
	
	}
}

#if 0
void stu_main()
{
	stu_node *head=NULL;
	FILE *fp;
	fp=fopen("stufile.data","r");
	head = file2node(fp);
	print_link(head);
	printf("********************\n");
	head = add_node(head);
	print_link(head);
}
#endif
