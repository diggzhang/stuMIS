/*
	结点写入文件
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "teacher.h"

void readhead2file(stu_node *head)
{
	stu_node *p=NULL;
	FILE *fp;
	fp=fopen("stufile.data","w");

	for(p=head; p!=NULL; p=p->next)
	{
		fprintf(fp,"%d %s %s %d %d %d %d %d %d\n",p->id,p->name,p->passwd,p->age,p->in_class,p->math,p->clang,p->yuwen,p->mingci);	
	}

	fclose(fp);
}

void t_readhead2file(t_node *head)
{
	t_node *p=NULL;
	FILE *fp;
	fp=fopen("t_file.data","w");

	for(p=head; p!=NULL; p=p->next)
	{
		fprintf(fp,"%d %s %s %d\n",p->id,p->name,p->passwd,p->t_class);	
	}

	fclose(fp);
}
