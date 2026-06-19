#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node {
	int data;
    struct node *next;
};
int main(){
	struct node *p, *q, *head, *p1;
    int n, c, i;
    printf("请输入一个整数n：");    scanf("%d",&n);
    printf("请输入%d个整数：",n);   scanf("%d",&c);    
    head = malloc(sizeof(struct node));
    head->data = c;    head->next = NULL;
    for(i=2;i<=n;i++){
		scanf("%d",&c);
		p = head;
		q = malloc(sizeof(struct node));
        q->data = c;
        while((p->next != NULL) && (p->next->data <= c))
			p = p->next;
        if((p->next == NULL)){
			if((p==head) && (p->data > c)){
				q->next = p;
				head = q;   
            }else{
                q->next = NULL;
				p->next = q;
            }
        }else{
			if((p==head) && (p->data > c)){
				q->next = p;
				head = q;   
            }else{
				p1 = p->next;
				q->next = p1;
				p->next = q;
            }
        }
    }
    for(p=head;p!=NULL;p=p->next)
		printf("%d ",p->data);
	system("pause");	return 0;
}
