/*
	修改密码
*/
#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"
#include "student.h"

stu_node *change_passwd(stu_node *head,int id)
{
	stu_node *q=NULL;
	for(q=head; q!=NULL; q=q->next)
	{
		if(q->id == id)
			break;
	}

	printf(">请输入新的密码：");
	scanf("%s",q->passwd);
	getchar();
	
	return head;
}

t_node *t_change_passwd(t_node *head,int id)
{
	t_node *q=NULL;
	for(q=head; q!=NULL; q=q->next)
	{
		if(q->id == id)
			break;
	}

	printf(">>请输入新的密码：");
	scanf("%s",q->passwd);
	getchar();
	
	return head;
}

