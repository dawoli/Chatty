#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,number[10]={6,2,5,5,4,5,6,3,7,6},len,jie;
bool f;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		if(n<2)
		{
			printf("-1\n");
			continue;
		}
		if(n%7==0)
		{
			len=n/7;
			for(int i=1;i<=len;i++)
				printf("8");
			printf("\n");
			continue;
		}
		else len=n/7+1;
		for(long long i=1;i<=len;i++)
		{
			if(f==1)
			{
				printf("8");
				continue;
			}
			jie=n-(len-i)*7;
			if(i==len)
			{
				for(int j=0;j<=9;j++)
					if(number[j]==jie&&(len!=1||j!=0))
					{
						printf("%lld",j);
						break;
					}
				break;
			}
			for(int j=0;j<=9;j++)
			{
				if((i!=1||j!=0)&&number[j]>=jie)
				{
					printf("%lld",j);
					n-=number[j];
					if(number[j]==jie)f=1;
					break;
				}
			}	
		}
		printf("\n");
	}
	return 0;
}
