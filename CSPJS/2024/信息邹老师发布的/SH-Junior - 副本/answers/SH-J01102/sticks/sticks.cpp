/*拼出的位数越小越好*/
#include<bits/stdc++.h>
using namespace std;
int n,num[12]={6,2,5,5,4,5,6,3,7,6};
int _min=INT_MAX;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,i,n,j,p;
	scanf("%d",&t);
	for(i=0;i<t;++i)
	{
		scanf("%d",&n);
		if(n<=1)
			printf("-1\n");
		else if(n%7==0&&n>=100)//特殊性质A
		{
			p=n/7;
			for(j=0;j<p;++j)
				printf("8");
			printf("\n");
		}
		else if(n%7==1&&n>=100)//特殊性质B
		{
			p=(n-1)/7-1;
			for(j=0;j<p;++j)
				printf("8");
			printf("16");
			printf("\n");
		}
		else if(n<=50)//处理<50的数据
		{
			bool ea=false;
			p=n/7;
			for(j=0;j<p;++j)
				printf("8");
			p=n-(p*7);
			for(j=0;j<10;++j)
			{
				if(num[j]==p&&(ea||j!=0))
				{
					printf("%d\n",j);
					break;
				}
				ea=true;
			}
		}
		else//难爆了区域//
		{
			p=n/7;
			for(j=0;j<p;++j)
				printf("8");
			p=n-(p*7);
			for(j=0;j<10;++j)
			{
				if(num[j]==p)
				{
					printf("%d\n",j);
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
