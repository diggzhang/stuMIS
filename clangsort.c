/*
	C语言排名
*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

stu_node *csort(stu_node *head,int pos)
{
	
	stu_node *p=NULL;
	int avg=0;
	int sum=0;
	int count=0;
	int mingci=0;

	for(p=head; p!=NULL; p=p->next)
	{
		if(p->in_class == pos)
			mingci++;
	}
	
	printf("本班同学以C语言成绩排名结果：\n");
	printf("学号\t姓名\tC语言成绩\t名次\n");
	for(p=head; p!=NULL; p=p->next)
	{
		if(p->in_class == pos)
		{
			++count;
			sum = sum + (p->clang);
			printf("%d\t%s\t%d\t\t%d\n",p->id,p->name,p->clang,mingci--);
		}
	}
	printf(">>C语言平均成绩：%d\n",avg=sum/count);
	return head;
}
