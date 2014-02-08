/*
	密码检查
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "teacher.h"

stu_node *check_password(stu_node *head,char *name,char *passwd)
{
	stu_node *p=NULL;
	getchar();

	for(p=head; p!=NULL; p=p->next)
	{
		if(!strcmp(p->name,name) && !strcmp(p->passwd,passwd))
			return p;
	}

	if(p == NULL)
		return p;
}

t_node *t_check_password(t_node *head,char *name,char *passwd)
{
	t_node *p=NULL;
	getchar();

	for(p=head; p!=NULL; p=p->next)
	{
		if(!strcmp(p->name,name) && !strcmp(p->passwd,passwd))
			return p;
	}

	if(p == NULL)
		return p;
}
