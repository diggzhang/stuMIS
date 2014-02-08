/*
教师修改学生成绩	
*/
#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"
#include "student.h"

stu_node *change_score(stu_node *head)
{
	stu_node *q=NULL;
	int id;
	while(1)
	{
		printf(">>请输入ID修改对应成绩:");
		scanf("%d",&id);
		getchar();

		for(q=head; q!=NULL; q=q->next)
		{
			if(q->id == id)
				break;
		}

		printf(">>请输入%s的数学成绩：",q->name);
		scanf("%d",&q->math);
		getchar();
		printf(">>请输入%s的C语言成绩：",q->name);
		scanf("%d",&q->clang);
		getchar();
		printf(">>请输入%s的语文成绩：",q->name);
		scanf("%d",&q->yuwen);
		getchar();

		break;
	}
}
