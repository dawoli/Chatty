#include<bits/stdc++.h>
using namespace std;
int num[15]={6,2,5,5,4,5,6,3,7,6};
int s,m,n;
void dfs(int layer,int sum,int p,int v)
{
	if(sum==n)
	{
		s=min(s,v);
		return;
	}
	if(layer>m)
		return;
	if(sum>n)
		return;
	int d;
	if(layer==1)
		d=1;
	else
		d=0;
	for(int i=d;i<=9;i++)
		dfs(layer+1,sum+num[i],p/10,v+p*i);
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		if(n%7==0)
		{
			for(int j=1;j<=n/7;j++)
				printf("8");
			printf("\n");
			continue;
		}
		if(n%7==1)
		{
			printf("10");
			for(int j=1;j<n/7;j++)
				printf("8");
			printf("\n");
			continue;
		}
		s=INT_MAX;
		m=ceil(n*1.0/7);
		dfs(1,0,pow(10,m-1),0);
		if(s==INT_MAX)
			printf("-1\n");
		else
			printf("%d\n",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
