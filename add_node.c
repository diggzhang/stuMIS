/*
添加学生结点
*/
#include<stdio.h>
#include<stdlib.h>
#include "student.h"
stu_node *add_node(stu_node *head)
{
	stu_node *tail=NULL;
	stu_node *p=NULL;
	p=malloc(sizeof(stu_node));
	if(NULL == p)
	{
		printf("malloc error\n");
		exit(-1);
	}

	printf("请输入学号,默认填0\n");
	scanf("%d",&p->id);
	getchar();
	printf("请输入 姓名\n");
	scanf("%s",p->name);
	getchar();
	printf("请输入 密码\n");
	scanf("%s",p->passwd);
	getchar();
	printf("请输入 年龄\n");
	scanf("%d",&p->age);
	getchar();
	printf("请输入 班级\n");
	scanf("%d",&p->in_class);
	getchar();
	p->pre=NULL;
	p->next=NULL;
	
	tail=head;
	
	if(NULL == head)
	{
		head=p;
		return p;
	}
	else
	{
		while(tail->next != NULL)
			tail=tail->next;
		tail->next =p;
		p->pre=tail;
	}

	printf("成功添加：%s\n",p->name);
	return head;
}
