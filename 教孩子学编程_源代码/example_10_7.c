#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{ 
    int data;
    struct node *next;
} *head, *q, *p;
void ins(struct node *p, int x){
	struct node *new;
    new = malloc(sizeof(struct node));
    new->data = x;
    new->next = p->next;
    p->next =new;
}
void print(){
    for(q=head; q!=NULL; q=q->next)
		printf("%d ",q->data);
    printf("\n");	
}
int main(){
	int i,n;
    printf("请输入一个正整数n：");    scanf("%d",&n);
	head = malloc(sizeof(struct node));   //创建初始链表
    head->data = 1;    head->next = NULL;
    q = head;
    for(i=2; i<=n; i++){  //循环插入2~n
		ins(q,i);
        q = q->next; 
    }
    print();
    for(q=head; q!=NULL; q=q->next){  //查找偶数并在后面插入2
		if((q->data)%2==0){
			ins(q,2);
            q = q->next;
        }
    }
    print();
    system("pause");
    return 0;
}
