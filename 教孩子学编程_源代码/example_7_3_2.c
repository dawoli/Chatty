#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int n,i=0;
    double D=0;
    printf("输入一个正整数：\n");
    scanf("%d",&n);
    do{
		if(n%2==1) D+=pow(10,i); //D=(n%2)*pow(10,i)
        n/=2;               //n=n/2
        i++;                //i=i+1
    }while(n!=0);     //非0，则重复“除2取余”转换
    printf("二进制数序列是：%.0lf\n",D);
	system("pause");
	return 0;
}
