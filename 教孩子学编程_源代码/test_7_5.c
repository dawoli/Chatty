#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, j, n;
    printf("输入一个正整数n，表示心形突出部分高度：\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){             //输出突出部分三角形的n行
		for(j=1;j<=n-i;j++)        //行首空格
			printf(" ");
		for(j=1;j<=2*i-1;j++)      //左三角形的#部分
			printf("#");
		for(j=1;j<=2*(n-i);j++)    //上三角形中间的空格部分
			printf(" ");
		for(j=1;j<=2*i-1;j++)      //右三角形的#部分
			printf("#");
        printf("\n");
    }
    for(i=1;i<=2*n-1;i++){         //输出下三角形的2n-1行
		for(j=1;j<=i-1;j++)        //行首空格
			printf(" ");
		for(j=1;j<=4*n-2*i;j++)    //下三角形的#部分
			printf("#");
        printf("\n");
    }
    printf("\n");
	system("pause");
	return 0;
}
