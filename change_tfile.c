/*
	修改教师信息
*/
#include <stdio.h>
#include <stdlib.h>
#include "teacher.h"
#include "student.h"

t_node *change_tfile(t_node *head)
{
	t_node *q=NULL;
	int id;
	while(1)
	{
		printf(">>请输入ID修改对应教师信息:");
		scanf("%d",&id);
		getchar();

		for(q=head; q!=NULL; q=q->next)
		{
			if(q->id == id)
				break;
		}

		printf(">>>请输入%s的名字：",q->name);
		scanf("%s",q->name);
		getchar();
		printf(">>>请输入%s的密码：",q->name);
		scanf("%s",q->passwd);
		getchar();
		printf(">>>请输入%s的所带班级：",q->name);
		scanf("%d",&q->t_class);
		getchar();

		break;
	}
}

stu_node *change_stufile(stu_node *head)
{
	stu_node *q=NULL;
	int id;
	while(1)
	{
		printf(">>请输入ID修改对应学生信息:");
		scanf("%d",&id);
		getchar();

		for(q=head; q!=NULL; q=q->next)
		{
			if(q->id == id)
				break;
		}

		printf(">>>请输入%s的名字：",q->name);
		scanf("%s",q->name);
		getchar();
		printf(">>>请输入%s的密码：",q->name);
		scanf("%s",q->passwd);
		getchar();
		printf(">>>请输入%s的所在班级：",q->name);
		scanf("%d",&q->in_class);
		getchar();
		printf(">>>请输入%s的数学成绩：",q->name);
		scanf("%d",&q->math);
		getchar();
		printf(">>>请输入%s的C语言成绩：",q->name);
		scanf("%d",&q->clang);
		getchar();
		printf(">>>请输入%s的语文成绩：",q->name);
		scanf("%d",&q->yuwen);
		getchar();

		break;
	}
}
