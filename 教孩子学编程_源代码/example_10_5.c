#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");
    int i;
    int a[5]={1,2,3,4,5};
    int *p = a;  //指针p指向a[0]
    printf("指向各元素的指针的表达式及值：\n");
    printf("     a = %p    p = %p\n",a,p);
    for(i=0;i<5;i++)
    {
		printf(" &a[%d] = %p  a+%d = %p  ",i,&a[i],i,a+i);
		printf("&p[%d] = %p  p+%d = %p\n",i,&p[i],i,p+i);
    }
    printf("\n各元素的表达式及值：\n");
    printf("   *a = %d  *p = %d\n",*a,*p);
    for(i=0;i<5;i++)
    {
		printf(" a[%d] = %d  *(a+%d) = %d  ",i,a[i],i,*(a+i));
		printf("p[%d] = %d  *(p+%d) = %d\n",i,p[i],i,*(p+i));
    }
    printf("\n\n");
    system("pause");
	return 0;
}
