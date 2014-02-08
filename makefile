main:main.c menu.c add_node.c stu_readfile.c t_readfile.c del_node.c find_node_byid.c t_del_node.c t_add_node.c  sortbyscore.c stu_add_node.c checkpasswd.c change_passwd.c readhead2file.c readhead2file.c student.h clangsort.c find_node_byname.c change_score.c t_find_node_byclass.c change_tfile.c find_node_byclass.c stu_add_node.c teacher.h
#main:main.o menu.o
#headfile = student.h teacher.h

#readfile = student.h teacher.h readhead2file.c stu_readfile.c t_readfile.c 

#add_node = student.h add_node.c
#del_node = student.h del_node.c
#find_node = student.h find_node.c

#t_add_node = teacher.h t_add_node.c stu_add_node.c
#t_del_node = teacher.h t_del_node.c
#t_find_node = teacher.h t_find_node_byclass.c

#change_passwd = $(headfile) change_passwd.c
#check_passwd = $(headfile) checkpasswd.c

#readfile = $(headfile) stu_readfile.c t_readfile.c 

#sort = $(headfile) sortbyscore.c clangsort.c
#change = $(headfile) change_score.c change_tfile.c
#findany = $(headfile) find_node_byclass.c find_node_byid.c find_node_byname.c

.PHONY:clean
clean:
	rm -f *.o main
