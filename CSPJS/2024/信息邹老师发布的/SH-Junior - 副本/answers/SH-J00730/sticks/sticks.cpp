#include<iostream>
#include<stdio.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int power(int x,int t)
{
	int w=1;
	for(int i=1;i<=t;i++)
	{
		w*=10,w+=1;
	}
	return w*x;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0)
		{
			printf("%d",power(8,n/7));
		}
		else if(n<=7)
		{
			for(int i=1;i<=9;i++)
				if(num[i]==n)
				{
					cout<<i<<endl;
					break;
				}
		}
		else
		{
			int ans=0;
			int w=n/7+1,fw; 
			for(int i=1;i<=9;i++)
			{
				if(num[i]+7*(w-1)>=n)
				{
					fw=i,n-=num[i];
					break;
				}
			}
			ans=fw;
			for(int i=2;i<=w;i++)
			{
				for(int j=0;j<=9;j++)
				{
					if((num[j]+2*(w-i)<=n)&&(num[j]+7*(w-i)>=n))
					{
						n-=num[j];
						ans=ans*10+j;
						break;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

