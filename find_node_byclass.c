/*
	按班级查找
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

stu_node *find_node_byclass(stu_node *head,int class)
{
	stu_node *p=NULL;
	int mingci=1;
	printf("\n");
	for(p=head; p!=NULL; p=p->next)
	{
		if(p->in_class == class)
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",p->id,p->name,p->age,p->in_class,p->math,p->clang,p->yuwen,mingci++);	
	}	

	getchar();
}
