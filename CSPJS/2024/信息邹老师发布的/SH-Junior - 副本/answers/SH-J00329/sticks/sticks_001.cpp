#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int T;
int n;

int num[50005];
int ans[50005];
int l1,l2;

bool cmp()
{
	int i;
	if(l1<l2) return 1;
	if(l1>l2) return 0;
	for(i=0;i<=l1;i++)
	{
		if(num[i]<ans[i]) return 1;
		if(num[i]>ans[i]) return 0;
	}
	return 0;
}
void cpy()
{
	int i;
	for(i=0;i<=l2;i++) ans[i]=num[i];
	l2=l1;
}
void out()
{
	int i;
	for(i=0;i<=l2;i++) printf("%d",ans[i]);
}
void dfs(int x,int d)
{
	l1=d-1;
	int i;
	if(x==0)
	{
		if(cmp())
		{
			cpy();
		}
	}
	for(i=0;i<10;i++)
	{
		if(x-a[i]>=0)
		{
			num[d]=i;
			dfs(x-a[i],d+1);
		}
	}
	num[d]=0;
}

void solve(int x)
{
	int i;
	memset(ans,0,sizeof(ans));
	ans[50000]=1;
	l2=50000;
	for(i=1;i<10;i++)
	{
		if(x-a[i]>=0)
		{
			num[0]=i;
			dfs(x-a[i],1);
		}
	}
	if(ans[50000]==1)
	{
		cout<<-1;
	}
	else
	{
		out();
	}
	num[0]=0;
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int ii,i;
	memset(num,0,sizeof(num));
	
	cin>>T;
	for(ii=0;ii<T;ii++)
	{
		cin>>n;
		if(n%7==0)
		{
			for(i=0;i<n/7;i++)
				printf("8");
		}
		else if(n%7==1 && n!=1)
		{
			printf("10");
			for(i=1;i<n/7;i++)
				printf("8");
		}
		else if(n>27)
		{
			solve(21+n%7);
			for(i=3;i<n/7;i++)
				printf("8");
		}
		else
		{
			solve(n);
		} 
		cout<<endl;
	}
	return 0;
}
