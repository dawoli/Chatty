#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{ 
    int d;
    struct node *next;
};
struct node *head, *p, *q;
int main(){
	int i,n;
    printf("请输入一个正整数n：");
    scanf("%d",&n);
	head = malloc(sizeof(struct node));   //创建初始链表
    head->d = 1;
    head->next = NULL;
    q = head;                             //初始链表表头就是表尾
    for(i=2; i<=n; i++){
		p = malloc(sizeof(struct node));  //申请内存空间
        q->next = p;                      //加入新结点
        p->d = i;
		p->next = NULL;
		q = p;                            //q指向表尾结点
    }
    for(p=head; p!=NULL; p=p->next){
		printf("%d ",p->d);
    }
    printf("\n");
    system("pause");
    return 0;
}
