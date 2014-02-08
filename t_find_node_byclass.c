/*
	按教师查找班级
*/
#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"

t_node *t_findnode_byclass(t_node *head,int clas)
{
	t_node *p=NULL;
	for(p=head; p!=NULL; p=p->next)
	{
		if(p->t_class == clas)
			return p;
	}	

	if(p == NULL)
		return p;
}
