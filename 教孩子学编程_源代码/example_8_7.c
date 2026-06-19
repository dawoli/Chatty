#include <stdio.h>
#include <stdlib.h>
int n,a[100][100];
void doubleCycle(int s)
{
	int i,j,k;
    for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
        {
			if(s==0) scanf("%d",&a[i][j]);  //读入矩阵
			if(s==1) printf("%5d",a[i][j]); //输出矩阵
			if(s==2 && i>j)                 //转置
            {
				k=a[i][j]; a[i][j]=a[j][i]; a[j][i]=k;
            }
        }
        if(s==1) printf("\n");
    }
}

int main()
{
    printf("输入一个正整数n（1<n<101）:");
    scanf("%d",&n);
    printf("依次输入%d*%d矩阵所有%d个元素:\n",n,n,n*n);
    doubleCycle(0);            //调用函数读入矩阵
    printf("原始矩阵:\n");
    doubleCycle(1);            //调用函数输出原矩阵
    doubleCycle(2);            //调用函数将原矩阵转置
    printf("转置以后的矩阵:\n");
    doubleCycle(1);            //调用函数输出转置结果
	system("pause");
	return 0;
}
