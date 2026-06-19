#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{ 
    int data;
    struct node *next, *pre;
} *head, *tail, *p, *new;                      //定义链表结点指针
int main(){
    int c;
    printf("请输入以空格分隔的若干整数（-1结束输入）：");
    head = malloc(sizeof(struct node));        //创建初始链表
    head->next = NULL;  head->pre = NULL;//初始化头结点指针域
    head->data = scanf("%d",&c);           //初始化头结点数值域
    p = head;                                           //当前指针赋值
    scanf("%d",&c);
    while(c != -1){                                   //循环插入结点
        new = malloc(sizeof(struct node));
        new->data = c;                            //新结点数值域赋值
        new->next = NULL;                  //新结点后继指针指向为空
        new->pre = p;                  //新结点前驱指针指向当前结点p
        p->next =new;               //当前结点p的后继指针指向新结点
        p = new;                      //当前结点指针重置为新插入的结点
        scanf("%d",&c);
    }
    tail = p;
    for(p=head; p!=NULL; p=p->next)      //从头到尾打印结点数据
        printf("%d ",p->data);
    printf("\n");
    for(p=tail; p!=NULL; p=p->pre)       //从尾到头打印结点数据
        printf("%d ",p->data); 
    system("pause");  return 0;
}
