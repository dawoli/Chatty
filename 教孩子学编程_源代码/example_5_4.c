#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");
	float s,v,p,k,t,liter,total;
    printf("\n请输入旅行的距离（千米）：");
    scanf("%f",&s);
    printf("请输入汽车平均速度（千米/小时）：");
    scanf("%f",&v);
    printf("请输入每公升汽油价格（元/公升）：");
    scanf("%f",&p);
    printf("请输入每公升汽油可行驶的距离（千米/公升）：");
    scanf("%f",&k);
    t = s/v;
    liter = s/k;
    total = liter*p;
    printf("\n旅行所需时间为：%.2f小时",t);
    printf("\n购买汽油的钱数为：%.2f元\n\n\n",total);
	system("pause");
	return 0;
}
