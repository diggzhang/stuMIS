/*
	读入教师data文件信息写为结点
*/
#include<stdio.h>
#include<stdlib.h>
#include "teacher.h"

t_node *t_add_node(t_node *head)
{
	t_node *tail=NULL;
	t_node *p=NULL;
	p=malloc(sizeof(t_node));
	if(NULL == p)
	{
		printf("malloc error\n");
		exit(-1);
	}

	printf("请输入教师编号，默认填0\n");
	scanf("%d",&p->id);
	printf("请输入 姓名\n");
	scanf("%s",p->name);
	getchar();
	printf("请输入 密码\n");
	scanf("%s",p->passwd);
	getchar();
	printf("请输入 负责班级\n");
	scanf("%d",&p->t_class);
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
