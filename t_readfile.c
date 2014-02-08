/*
	读入教师文件
*/
#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"

t_node *t_add_node(t_node *head);
t_node *t_file2node(FILE *fp)
{
	int re;
	t_node *p=NULL;
	t_node *head=NULL;
	t_node *tail=NULL;

	if(fp == NULL)
	{
		printf("教师信息表无法打开\n");
		getchar();
		exit(1);
	}

	while(1)
	{
		p=malloc(sizeof(t_node));
		if(NULL == p)
		{
			printf("malloc error\n");
			exit(-1);
		}
		p->pre=NULL;
		p->next=NULL;
	
		re = fscanf(fp,"%d %s %s %d\n",&p->id,p->name,p->passwd,&p->t_class);

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

void t_print_link(t_node *head)
{
	t_node *p=NULL;
	for(p=head; p!=NULL; p=p->next)
	{
		printf("%d\t%s\t%d\n",p->id,p->name,p->t_class);
	
	}
}

#if 0
void main()
{
	t_node *head=NULL;
	FILE *fp;
	fp=fopen("t_file.data","r");
	head = file2node(fp);
	print_link(head);
	printf("*************************\n");
	head = t_add_node(head);
	print_link(head);
}
#endif

