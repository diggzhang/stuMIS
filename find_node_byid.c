/*
	按ID查询
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "teacher.h"

stu_node *find_node(stu_node *head,int id)
{
	stu_node *p=NULL;
	getchar();
	for(p=head; p!=NULL; p=p->next)
	{
		if(p->id == id)
			return p;
	}	

	if(p == NULL)
		return p;
}

t_node *t_find_node(t_node *head,int id)
{
	t_node *p=NULL;
	getchar();
	for(p=head; p!=NULL; p=p->next)
	{
		if(p->id == id)
			return p;
	}	

	if(p == NULL)
		return p;
}
