#include <stdio.h>

typedef struct	teacher
{
	int id;
	char name[128];
	char passwd[32];
	int t_class;
	struct teacher *pre,*next;
}t_node;

t_node *t_file2node(FILE *fp);
void t_print_link(t_node *head);
t_node *t_add_node(t_node *head);
t_node *t_find_node(t_node *head,int id);
t_node *t_findnode_byclass(t_node *head,int clas);
t_node *t_check_password(t_node *head,char *name,char *passwd);
t_node *t_change_passwd(t_node *head,int id);
void t_readhead2file(t_node *head);
t_node *t_find_node_byname(t_node *head,char *name);
t_node *change_tfile(t_node *head);
