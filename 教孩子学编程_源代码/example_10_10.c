#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{
	int num;
	struct node *next;
};
struct node *head,*p,*q;
main(){
    int i,j,left;
    head=malloc(sizeof(struct node));
    head->num = 1;   //建立初始的链环
    head->next = head;
    q = head;
    for (i=2;i<=30;i++){ //以i作为数值域建立结点，并接入链环
      p = malloc(sizeof(struct node));
      p->num = i;
      q->next = p;
      p->next = head;
      q = p;
    }
    q = head;      //出列操作
    left = 30;
	do { //重复报数出列
		i = 1; //i作为报数器
		while (i < 9){  //循环报数，报m的出列
			p = q;
			i = i+1;
			q = q->next;
		}
		printf("%2d ",q->num);   //输出出列人的编号
		left = left-1;    //圈内剩余人数
		p->next = q->next;
		free(q);     //释放该结点
		q = p->next;
	} while (left > 15);   //直到圈里还剩15人，结束操作
	printf("\n");
	for(i=1;i<=15;i++){
		printf("%2d ",q->num);
        q = q->next;
    }
	system("pause");
	return 0;
}
