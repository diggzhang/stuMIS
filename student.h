#include <stdio.h>

typedef struct student
{
	int id;
	char name[128];
	char passwd[32];
	int age;
	int in_class;
	int math;
	int clang;
	int yuwen;
	int mingci;
	struct student *pre,*next;
}stu_node;

stu_node *file2node(FILE *fp);
void print_link(stu_node *head);
stu_node *add_node(stu_node *head);
stu_node *del_node(stu_node *head,int key);
stu_node *find_node(stu_node *head,int id);
stu_node *stu_add_node(stu_node *head);
stu_node *get_max_node(stu_node *head);
stu_node *del_min_node(stu_node *head,stu_node *max);
stu_node *add_node_new(stu_node *head,stu_node *max);
stu_node *stu_sort_link(stu_node *head);
stu_node *check_password(stu_node *head,char *name,char *passwd);
stu_node *change_passwd(stu_node *head,int id);
void readhead2file(stu_node *head);
stu_node *find_node_byname(stu_node *head,char *name);
stu_node *change_stufile(stu_node *head);
