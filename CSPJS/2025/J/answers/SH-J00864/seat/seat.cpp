#include<bits/stdc++.h>
using namespace std;
/*
输入
用特殊变量保存小A的成绩，然后对成绩排序，推理找到它的座位 
*/
int n,m,a[105],your,sec;//your:小A的分数 sec:排序后他的座位号 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,a+1);
	your=a[1];
	for(int i=2;i<=m*n;i++)
	{
		scanf("%d",a+i);
	}
	sort(a+1,a+1+n*m,greater<>());
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==your)
		{
			sec=i;
			break;
		}
	}
	int c=(sec+n-1)/n;
	int r=(sec+n-1)%m+1;
	if(c%2==0)//这里如果出现3221225620，因该是c没输入，传值就不会这样
	{
		printf("%d %d",c,m-r+1);
	}
	else
	{
		printf("%d %d",c,r);
	}
	return 0; 
}
