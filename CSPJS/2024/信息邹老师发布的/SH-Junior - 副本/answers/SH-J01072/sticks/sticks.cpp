#include<bits/stdc++.h>
using namespace std;
int _7(int a)
{
	if(a==7)
		return 8;
	else if(a==8)
		return 10;
	else if(a==9)
		return 18;
	else if(a==10)
		return 22;
	else if(a==11)
		return 20;
	else if(a==12)
		return 18;
	else 
		return 80;
}
int fun(int a)
{
	if(a<=1)
		return -1;
	else if(a==2)
		return 1;
	else if(a==3)
		return 7;
	else if(a==4)
		return 4;
	else if(a==8)
		return 10;
	else if(a==5)
		return 2;
	else if(a==6)
		return 6;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long a=0,t;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&a);
		if(a<=6)
			printf("%d\n",fun(a));
		else
		{
			printf("%d",_7(a%7+7));
			for(a=(a-7-(a%7))/7;a>0;a--)
				printf("8");
			printf("\n");
		}
	}
	return 0;
}
