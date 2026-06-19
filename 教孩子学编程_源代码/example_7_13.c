#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,i,j;
    printf("输入欲打印的行数n（2<n≤20）：");
    scanf("%d",&n);
    if(n>20) n=20;
    long t[20][20]={[0][0]=1,[1][0]=1,[1][1]=1};//前2行赋初值
    for(i=2;i<n;i++)  //用for循环给3～n行元素赋值
	{
		t[i][0]=1;
        for(j=1;j<i;j++)
			t[i][j]=t[i-1][j-1]+t[i-1][j];
        t[i][i]=1;		
    }
    for(i=0;i<n;i++)  //输出杨辉三角形
    {
		for(j=0;j<=i;j++)  //用for循环遍历并打印一行所有数字
			printf("%d ",t[i][j]);
        printf("\n");  //打印完一行后换行        
    }
	system("pause");
	return 0;
}
