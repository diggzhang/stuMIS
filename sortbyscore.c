/*
	结点排序
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

stu_node *get_max_node(stu_node *head)
{
	stu_node *p=NULL;
	stu_node *max=NULL;
	int score=0;
	int maxscore=0;
	max=head;
	for(p=head; p!=NULL; p=p->next)
	{
		if(max->clang <= p->clang)
			max=p;
	}

	return max;
}

stu_node *del_max_node(stu_node *head,stu_node *max)
{
	stu_node *p=NULL;
	stu_node *pp=NULL;

	for(p=head,pp=p; p!=NULL; pp=p,p=p->next)
	{
		if(p == max)
			break;
	}

	if(p == NULL)
	{
		return head;
	}
	else if(p == head)
	{
		head = p->next;
		return head;
	}
	else
	{
		pp->next = p->next;
		return head;
	}

}

stu_node *add_node_new(stu_node *head_new,stu_node *max)
{
	max->next = head_new;
	head_new = max;
	return head_new;
}

stu_node *stu_sort_link(stu_node *head)
{
	stu_node *head_new = NULL;
	stu_node *max_p=NULL;

	while(head != NULL)
	{
		max_p = get_max_node(head);
		head = del_max_node(head,max_p);
		head_new = add_node_new(head_new,max_p);
	}
	return head_new;
}
