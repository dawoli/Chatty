#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
       int data;
       struct node *next;
} *head,*p,*q;
main()
{
    long n,m,i,left;
    printf("请输入总人数n（n>0）：");
    scanf("%d",&n);
    printf("请输入出列序号m（0<m<n）：");
    scanf("%d",&m);
    head=malloc(sizeof(struct node));
    head->data=1;   //建立初始的链环
    head->next=head;
    q=head;
    for (i=2;i<=n;i++) //以i作为数值域建立结点，并接入链环
    {
      p=malloc(sizeof(struct node));
      p->data=i;
      q->next=p;
      p->next=head;
      q=p;
      }
    q=head;      //出列操作
    printf("\n出列顺序：");
    left=n;
    do { //重复报数出列
     i=1; //i作为报数器
     while (i<m)  //循环报数，报m的出列
     {
       p=q;
       i=i+1;
       q=q->next;
       }
       printf("%d ",q->data);   //输出出列人的编号
       left=left-1;
       p->next=q->next;
       free(q);     //释放该结点
       q=p->next;
     } 
   while  (left!=0);   //直到圈里无人，结束操作
   printf("\n\n");
   system("pause");
   return 0;
}
