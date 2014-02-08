/******************************************
功能：主屏图形输出
创建日期：20130810
版本:2.8
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "teacher.h"
#define _COMMENT_ 0
#define _OUT_ '0'
//获取字符函数
char print_get()
{
	char ch;
	printf("\n\n\n");

	printf("选择：");
	ch = getchar();
	getchar();
	
	return ch;
}

void print_star()
{
	printf("*****************************************************\n");
}

pass_check()
{
	system("clear");
	print_star();
	printf("\t\t请输入用户名/密码\n");
	printf("\t\t默认 name:admin password:admin\n");
	print_star();

}
//stu modify 444
#define _ADDSTU_ '1'
#define _DELSTU_ '2'
#define _SEARCHBYID_ '3'
#define _SORTBYC_ '4'
#define _CHANGESCORE_ '5'
void stu_modify(t_node *t_head,t_node *t_pass,stu_node *head)
{
	while(1)
	{
		system("clear");

		print_star();
		printf("\t\t1)添加学生\n");
		printf("\t\t2)删除学生\n");
		printf("\t\t3)按ID查找\n");
		printf("\t\t4)C语言成绩排名\n");
		printf("\t\t5)修改成绩\n");
		printf("\t\t0)返回上一级\n");
		print_star();
#if 1
//		stu_node *head = NULL;
		stu_node *new = NULL;
		stu_node *p=NULL;
//		FILE *fp;
//		fp=fopen("stufile.data","r");
//		head = file2node(fp);
#endif
		printf("学号\t姓名\t年龄\t班级\t数学\tC语言\t语文\t排名 \n");
		find_node_byclass(head,(t_pass->t_class));

		char ch;
		int id;
		ch=print_get();
		switch(ch)
		{
			case _ADDSTU_:
				printf(">>请输入添加学生信息\n");
				head= stu_add_node(head);
				break;
			case _DELSTU_:
				printf(">>请输入删除学生的ID\n");
				printf(">>");
				scanf("%d",&id);
				del_node(head,id);
				printf(">>删除成功<<\n");
				getchar();
				break;
			case _SEARCHBYID_:
				printf(">>请输入查找学生的ID\n");
				printf(">>");
				scanf("%d",&id);
				p=find_node(head,id);
				if(p == NULL)
				{
					printf("没有发现查询信息\n");
				}
				else
				{
					printf("学号：%d 姓名：%s \n",p->id,p->name);
				}
				getchar();
				break;
			case _SORTBYC_:
				stu_sort_link(head);
				csort(head,(t_pass->t_class));
				getchar();
				break;
			case _CHANGESCORE_:
				change_score(head);
				getchar();
				break;
			case _OUT_:
				printf(">>数据变动，是否保存？（Y/N）");
				printf(">>");
				ch=getchar();getchar();
				if(ch == 'y' || ch == 'Y')
				{
					readhead2file(head);
					printf("数据存盘成功\n");
				}
				else
				{
					printf("数据变动，未存盘\n");
				}
				printf(">>修改完成<<");
				getchar();
				return;
		}
	}
}

//stu 333
void my_info(stu_node *pass)
{
	while(1)
	{
		system("clear");
		char ch;
		print_star();
		printf("\t\t我的个人信息\n");
		printf("\t\t按'0'返回\n");
		print_star();

		printf("学号\t姓名\t年龄\t班级\t数学\tC语言\t语文\t排名 \n");
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",pass->id,pass->name,pass->age,pass->in_class,pass->math,pass->clang,pass->yuwen,pass->mingci);
	
		ch=print_get();
		if(ch == '0')
			return;
	}
}

#define _STUCHANGEPASSWD_ '1'
void edit_myinfo(stu_node *head,stu_node *pass)
{
	stu_node *newhead=NULL;
	while(1)
	{
		system("clear");
		char ch;
		print_star();
		printf("\t\t按'1'修改密码\n");
		printf("\t\t按'0'返回\n");
		print_star();
	
		printf("学号\t姓名\t年龄\t班级\t数学\tC语言\t语文\t排名 \n");
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",pass->id,pass->name,pass->age,pass->in_class,pass->math,pass->clang,pass->yuwen,pass->mingci);

		ch=print_get();

		switch(ch)
		{
			case _STUCHANGEPASSWD_:
				newhead=change_passwd(head,(pass->id));
				printf(">>数据变动，是否保存？（Y/N）");
				printf(">>");
				ch=getchar();getchar();
				if(ch == 'y' || ch == 'Y')
				{
					readhead2file(newhead);
					printf("数据存盘成功\n");
				}
				else
				{
					printf("数据变动，未存盘\n");
				}
				printf(">>修改完成<<");
				getchar();
				break;
			case _OUT_:
				return;
		}
	}
}

//teacher 333

void t_myinfo(t_node *t_pass)
{
	while(1)
	{
		system("clear");
		char ch;
		print_star();	
		printf("\t\t教师信息\n");
		printf("\t\tpress '0' return to main menu\n");
		print_star();	
	
		printf("教师号\t姓名\t负责班级\n");
		printf("%d\t%s\t%d\n",t_pass->id,t_pass->name,t_pass->t_class);

		ch=print_get();
		if(ch == '0')
			return;
	}
}
#define _CHANGEPASSWD_ '1'
void t_editmyinfo(t_node *t_head,t_node *t_pass)
{
	t_node *newhead=NULL;
	while(1)
	{
		system("clear");
		char ch;
		print_star();	
		printf("\t\t修改密码\n");
		printf("\t\t1)修改密码\n");
		printf("\t\t0)按'0'返回\n");
		print_star();	
	
		printf("教师号\t姓名\t负责班级\n");
		printf("%d\t%s\t%d\n",t_pass->id,t_pass->name,t_pass->t_class);

		ch=print_get();

		switch(ch)
		{
			case _CHANGEPASSWD_:
				newhead=t_change_passwd(t_head,(t_pass->id));
				printf(">>数据变动，是否保存？（Y/N）");
				printf(">>");
				ch=getchar();getchar();
				if(ch == 'y' || ch == 'Y')
				{
					t_readhead2file(newhead);
					printf("数据存盘成功\n");
				}
				else
				{
					printf("数据变动，未存盘\n");
				}
				printf(">>修改成功<<\n");
				getchar();
				break;
			case _OUT_:
				return;
		}
	}
}

#define _TMANAGE_ '1' 
void my_stu(t_node *t_head,t_node *t_pass,stu_node *head)
{
	while(1)
	{
		system("clear");
		char ch;
		print_star();	
		printf("\t\t我的学生\n");
		printf("\t\t按'1'进入教师管理模式\n");
		printf("\t\t按'0'返回上一级\n");
		print_star();	
#if 1
	//	stu_node *head = NULL;
		stu_node *new = NULL;
		stu_node *p=NULL;
	//	FILE *fp;
	//	fp=fopen("stufile.data","r");
	//	head = file2node(fp);
#endif
		printf("学号\t姓名\t年龄\t班级\t数学\tC语言\t语文\t排名 \n");
		find_node_byclass(head,(t_pass->t_class));

		ch=print_get();
		switch(ch)
		{
			case _TMANAGE_:
				stu_modify(t_head,t_pass,head);
				break;
			case _OUT_:
				return;
		}
	}
}
//root333
#define _ADDSTU_ '1'
#define _DELSTU_ '2'
#define _SEARCHSTUBYID_ '3'
#define _SEARCHSTUBYNAME_ '4'
#define _MODIFYSTUINFO_ '5'
#define _DISPLAYCLASS_ '6'
void stu_all(stu_node *head,t_node *t_head)
{
	while(1)
	{
		system("clear");
		print_star();
		printf("\t\t全部学生信息\n");
		printf("\t\t1)添加学生\n");
		printf("\t\t2)删除学生\n");
		printf("\t\t3)按ID查找学生\n");
		printf("\t\t4)按姓名查找学生\n");
		printf("\t\t5)修改学生信息\n");
		printf("\t\t6)查看班级\n");
		printf("\t\tPress '0' return to main menu\n");
		print_star();
#if 1
	//	stu_node *head = NULL;
		stu_node *new=NULL;
		stu_node *p=NULL;
	//	FILE *fp;
	//	fp=fopen("stufile.data","r");
	//	head = file2node(fp);
#endif
		printf("学号\t姓名\t年龄\t班级\t数学\tC语言\t语文\t排名 \n");
		print_link(head);

		char ch;
		int id;
		char search[23];
		ch=print_get();
		
		switch(ch)
		{	
			case _ADDSTU_:
				printf(">>>请输入添加学生信息\n");
				new = add_node(head);	
				//printf("学号\t姓名\t年龄\t班级\t数学\tC语言\t语文\t排名 \n");
				//print_link(new);
				getchar();
				break;
			case _DELSTU_:
				printf(">>>请输入删除学生的ID\n");
				printf(">>>");
				scanf("%d",&id);
				del_node(head,id);
				printf(">>>删除成功<<<\n");
				getchar();
				break;
			case _SEARCHSTUBYID_:
				printf(">>>请输入查找学生的ID\n");
				printf(">>>");
				scanf("%d",&id);
				p=find_node(head,id);
				if(p == NULL)
				{
					printf("没有发现查询信息\n");
				}
				else
				{
					printf("学号：%d 姓名:%s 班级：%d \n",p->id,p->name,p->in_class);	
				}
				getchar();
				break;
			case _SEARCHSTUBYNAME_:
				printf(">>>请输入需查找学生的姓名\n");
				printf(">>>");
				scanf("%s",search);
				getchar();
				p=find_node_byname(head,search);
				if(p == NULL)
				{
					printf("没有发现查询信息\n");
				}
				else
				{
					printf("学号：%d 姓名:%s 班级：%d \n",p->id,p->name,p->in_class);
				}
				getchar();
				break;
			case _MODIFYSTUINFO_:
				change_stufile(head);	
				printf(">>数据变动，是否保存？（Y/N）");
				printf(">>");
				ch=getchar();getchar();
				if(ch == 'y' || ch == 'Y')
				{
					readhead2file(head);
					printf("数据存盘成功\n");
				}
				else
				{
					printf("数据变动，未存盘\n");
				}
				printf(">>修改完成<<\n");
				getchar();
				break;
			case _DISPLAYCLASS_:
				printf(">>>请输入要查询的班级\n");
				printf(">>>");
				scanf("%d",&id);
				printf("学号\t姓名\t年龄\t班级\t数学\tC语言\t语文\t排名 \n");
				find_node_byclass(head,id);
				getchar();
				break;
			case '7':
				stu_sort_link(head);
				getchar();
				break;
			case _OUT_:
				return;
		}
	
	}
}

#define _ADDT_ '1'
#define _DELT_ '2'
#define _SEARCHBYID_ '3'
#define _SEARCHBYNAME_ '4'
#define _MODIFYT_ '5'
void t_all(t_node *t_head)
{
	while(1)
	{
		system("clear");
		print_star();
		printf("\t\t全部教师信息\n");
		printf("\t\t1)添加教师\n");
		printf("\t\t2)删除教师\n");
		printf("\t\t3)按ID查找教师\n");
		printf("\t\t4)按姓名查找教师\n");
		printf("\t\t5)修改教师信息\n");
		printf("\t\tPress '0' return to main menu\n");
		print_star();
#if 0
		t_node *head = NULL;
		FILE *fp;
		fp = fopen("t_file.data","r");
		head = t_file2node(fp);
#endif
		t_node *p=NULL;
		printf("教师号\t姓名\t负责班级\n");
		t_print_link(t_head);

		char ch;
		char search[32];
		int id;
		ch=print_get();

		switch(ch)
		{
			case _ADDT_:
				printf(">>>请输入添加教师信息\n");
				t_add_node(t_head);
				getchar();
				break;
			case _DELT_:
				printf(">>>请输入删除教师ID\n");
				printf(">>>");
				scanf("%d",&id);
				t_del_node(t_head,id);
				printf(">>>删除成功<<<\n");
				getchar();
				break;
			case _SEARCHBYID_:
				printf(">>>请输入查找教师的ID\n");
				printf(">>>");
				scanf("%d",&id);
				p=t_find_node(t_head,id);
				if(p == NULL)
				{
					printf("没有发现查询信息\n");
				}
				else
				{
					printf("编号：%d 姓名:%s 负责班级：%d \n",p->id,p->name,p->t_class);	
				}
				getchar();
				break;
			case _SEARCHBYNAME_:
				printf(">>>请输入需查找教师的姓名\n");
				printf(">>>");
				scanf("%s",search);
				p=t_find_node_byname(t_head,search);
				getchar();
				if(p == NULL)
				{
					printf("没有发现查询信息\n");
				}
				else
				{
					printf("编号：%d 姓名:%s 负责班级：%d \n",p->id,p->name,p->t_class);
				}
				getchar();
				break;
			case _MODIFYT_:
				change_tfile(t_head);
				printf(">>数据变动，是否保存？（Y/N）");
				printf(">>");
				ch=getchar();getchar();
				if(ch == 'y' || ch == 'Y')
				{
					t_readhead2file(t_head);
					printf("数据存盘成功\n");
				}
				else
				{
					printf("数据变动，未存盘\n");
				}
				printf(">>修改完成<<\n");
				getchar();
				break;
			case _OUT_:
				return;

		}
	}
}

//管理员 222
#define _DISPLAYALLSTU_ '1'
#define _DISPLAYALLT_ '2'
void root_menu(stu_node *head,t_node *t_head)
{
	char ch;
	while(1)
	{
		system("clear");
		print_star();
		printf("**		1） 学生管理	**\n");
		printf("**		2） 教师管理	**\n");
		printf("**		0） 返回    	**\n");
		printf("**		>>> 管理员模式 <<< 	\n");
		print_star();

		ch=print_get();

		switch(ch)
		{
			case _DISPLAYALLSTU_:
				stu_all(head,t_head);
				break;
			case _DISPLAYALLT_:
				t_all(t_head);
				break;
			case _OUT_:
				return;
		}
	}
}
//学生 222
#define _MYINFO_ '1'
#define _EDITMYINFO_ '2'
void stu_menu(stu_node *head,stu_node *pass)
{
	while(1)
	{
		system("clear");
		char ch;
		print_star();
		printf("	1) 我的信息\n");
		printf("	2) 修改密码\n");
		printf("	0) 返回主菜单\n");
		print_star();
		printf("	欢迎");printf("%s 同学登入\n",(pass->name));
		print_star();

		ch=print_get();
		switch(ch)
		{
			case _MYINFO_:
				my_info(pass);
				break;
			case _EDITMYINFO_:
				edit_myinfo(head,pass);
				break;
			case _OUT_:
				return;
		}
	}
}
//教师 222
#define _TINFO_ '1'
#define _TEDITINFO_ '2'
#define _MYSTU_ '3'
void t_menu(t_node *t_head,t_node *t_pass,stu_node *head)
{
	while(1)
	{
		system("clear");
		print_star();
		printf("	1) 我的信息\n");
		printf("	2) 修改密码\n");
		printf("	3) 我的学生\n");
		printf("	0) 返回主菜单\n");
		print_star();
		printf("	欢迎");printf("%s 老师登入\n",(t_pass->name));
		print_star();

		char ch;
		ch=print_get();

		switch(ch)
		{
			case _TINFO_:
				t_myinfo(t_pass);
				break;
			case _TEDITINFO_:
				t_editmyinfo(t_head,t_pass);
				break;
			case _MYSTU_:
				my_stu(t_head,t_pass,head);
				break;
			case _OUT_:
				return;
		}

	}
}
//111
#define _STULOGIN_ '1'
#define _TLOGIN_ '2'
#define _ROOTLOGIN_ '3'
void menu()
{
	int i=0;
	char username[32];
	char passwd[62];
	char ch;
#if _COMMENT_
	pass/t_pass为通过密码验证后返回的用户验证结点
	读入学生/教师信息后生成链表head/t_head
#endif
	stu_node *pass=NULL;
	t_node *t_pass=NULL;
	stu_node *head=NULL;
	t_node *t_head=NULL;
	FILE *fp;
	FILE *tfp;
	fp=fopen("stufile.data","r");
	head = file2node(fp);
	tfp=fopen("t_file.data","r");
	t_head = t_file2node(tfp);

//	print_link(head);
//	t_print_link(t_head);
	//getchar();
	while(1)
	{
		system("clear");
		print_star();
		printf("**\n");
		printf("**		1) 学生登陆			 	\n");
		printf("**\n");
		printf("**		2) 教师登陆		   	 	\n");
		printf("**\n");
		printf("**		3) 管理员登陆		 	\n");
		printf("**\n");
		printf("**		0) 退出本程序 	 	     \n");
		print_star();
		
		ch='K';
		ch=print_get();

		switch(ch)
		{
			case _STULOGIN_:
				i=0;
				while(i<3)
				{
					printf("\n输入用户名：");
					scanf("%s",username);
					getchar();
					printf("输入密码 ：");
					scanf("%s",passwd);
					pass=check_password(head,username,passwd);
					if(pass == NULL)
					{
						printf("用户名/密码错误！\n");	
						printf("第%d次输入密码（3次错误后将自动退出）",i+1);
						i++;
					}
					else
					{
						stu_menu(head,pass);
						break;
					}
				}
				if(i==3)
				{
					printf("用户名或密码错误!\n");
					printf("退出学生管理系统\n");
					
				}
				break;
			case _TLOGIN_:
				i=0;
				while(i<3)
				{
					printf("\n输入用户名：");
					scanf("%s",username);
					getchar();
					printf("输入密码 ：");
					scanf("%s",passwd);
					t_pass=t_check_password(t_head,username,passwd);
					if(t_pass == NULL)
					{
						printf("用户名/密码错误！\n");	
						printf("第%d次输入密码（3次错误后将自动退出）",i+1);
						i++;
					}
					else
					{
						t_menu(t_head,t_pass,head);
						break;
					}
				}
				if(i==3)
				{
					printf("用户名或密码错误!\n");
					printf("退出学生管理系统\n");
				}
				break;
			case _ROOTLOGIN_:
				i=0;
				while(i<3)
				{
					printf("输入用户名：");
					scanf("%s",username);
					getchar();
					printf("输入密码 ：");
					scanf("%s",passwd);
					getchar();
					if(!strcmp(passwd,"admin") && !strcmp(username,"admin"))
					{
						root_menu(head,t_head);
						break;
					}
					i++;
					printf("第%d次输入密码（3次错误后将自动退出）\n",i+1);
				}
				if(i==3)
				{
					printf("用户名或密码错误!\n");
					break;
				}
				break;
			case _OUT_:
				system("clear");
				exit(0);
		}
	}
}
