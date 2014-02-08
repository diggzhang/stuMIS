/*
	按姓名查找
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "teacher.h"

stu_node *find_node_byname(stu_node *head,char *name)
{
	stu_node *p=NULL;
	for(p=head; p!=NULL; p=p->next)
	{
		if(!strcmp(p->name,name))
			return p;
	}

	if(p == NULL)
		return p;
}

t_node *t_find_node_byname(t_node *head,char *name)
{
	t_node *p=NULL;
	for(p=head; p!=NULL; p=p->next)
	{
		if(!strcmp(p->name,name))
			return p;
	}

	if(p == NULL)
		return p;
}
