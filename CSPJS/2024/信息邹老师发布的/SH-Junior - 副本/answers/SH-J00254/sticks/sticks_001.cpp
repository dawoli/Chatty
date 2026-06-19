#include<bits/stdc++.h>
using namespace std;

inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0'); 
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long T;
	T=read();
	while(T--)
	{
		long long n,flag=0;
		n=read();
		if(n==1)
		{
			printf("-1");
			printf("\n");
			flag=1;
		}
		else if(n==2)
		{
			printf("1");
			printf("\n");
			flag=1;
		}
		else if(n==3)
		{
			printf("7");
			printf("\n");
			flag=1;
		}
		else if(n==4)
		{
			printf("4");
			printf("\n");
			flag=1;
		}
		else if(n==5)
		{
			printf("2");
			printf("\n");
			flag=1;
		}
		else if(n==6)
		{
			printf("6");
			printf("\n");
			flag=1;
		}
		if(n%7!=1&&flag==0)
		{
			long long num8,num;
			num8=n/7;
			num=n%7;
			if(num==6)//0
			{
				printf("8");
				num8--;
				printf("0");
				for(int i=1;i<=num8;i++) printf("8");
				printf("\n");
			}
			else if(num==2)//1
			{
				printf("1");
				for(int i=1;i<=num8;i++) printf("8");
				printf("\n");
			}
			else if(num==3)//22
			{
				printf("22");
				for(int i=1;i<=num8-1;i++) printf("8");
				printf("\n");
			}
			else if(num==4)//20
			{
				printf("20");
				for(int i=1;i<=num8-1;i++) printf("8");
				printf("\n");
			}
			else if(num==5)//2
			{
				printf("2");
				for(int i=1;i<=num8;i++) printf("8");
				printf("\n");
			}
			else if(num==0)
			{
				for(int i=1;i<=num8;i++) printf("8");
				printf("\n");
			}
		}
		else if(flag==0)
		{
			long long num8;
			num8=(n/7)-1;
			printf("10");
			for(int i=1;i<=num8;i++) printf("8");
			printf("\n");
		}
	}
	return 0;
}
