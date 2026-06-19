#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node {
	int data;
    struct node *pre;
};
int main(){
	struct node *p, *q, *head;
    int c;
    printf("请输入以空格分隔的若干整数（-1结束输入）：");
    head = malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->pre = NULL;
    p = head;
    scanf("%d",&c);
    while(c!=-1){
		q = malloc(sizeof(struct node));
        q->data = c;
        q->pre = p;
        p = q;
        scanf("%d",&c);
    }
    while(p!=NULL){
		printf("%d ",p->data);
        p = p->pre;
    }
	system("pause");
	return 0;
}
