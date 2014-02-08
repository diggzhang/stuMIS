/*
	删除学生结点
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

stu_node *del_node(stu_node *head,int key)
{
	stu_node *p=NULL;
	stu_node *pp=NULL;
	for(p=head,pp=p;p!=NULL;pp=p,p=p->next)
	{
		if(p->id == key)
			break;
	}

	if(p==NULL)
		return head;
	if(p == head)
	{
		if(p->next != NULL)
			p->next->pre=NULL;
		head = p->next;
	}
	else if(p->next == NULL)
	{
		p->pre->next = NULL;
	}
	else
	{
		pp->next = p->next;
		p->next->pre = pp;
	}

	free(p);
	p=NULL;

	return head;
}
