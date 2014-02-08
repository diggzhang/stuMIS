/*
	删除教师
*/
#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"

t_node *t_del_node(t_node *head,int key)
{
	t_node *p=NULL;
	t_node *pp=NULL;
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
	
	FILE *fp;
	fp=fopen("t_file.data","w");
	for(p=head; p!=NULL; p=p->next)
	{
		fprintf(fp,"%d %s %s %d\n",p->id,p->name,p->passwd,p->t_class);
	}
	fclose(fp);

	return head;
}
