#include<bits/stdc++.h>
using namespace std;
int a[3000],finans[11]={-1};
bool aflag[3000],visited[3000];
int calculate(int n)
{
	int frnt=-1,ans=0;
	for(int i=0;i<n;i++)
	{
		if(aflag[i])
		{
			if(frnt==a[i])
			{
				ans+=a[i];
			}
			frnt=a[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!aflag[i])
		{
			if(frnt==a[i])
			{
				ans+=a[i];
			}
			frnt=a[i];
		}
	}
	return ans;
}
void dfs(int deep,int n,bool flag,int hao)
{
	if(deep==n-1)
	{
		finans[hao]=max(finans[hao],calculate(n));
		return;
	}
	aflag[deep]=flag;
	for(int i=0;i<2;i++)
	{
		dfs(deep+1,n,1,hao);
		dfs(deep+1,n,0,hao);
	}
}
void color(int hao)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dfs(0,n,1,hao);
	dfs(0,n,0,hao);
}
int main()
{
	freopen("color2.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		for(int i=0;i<1000;i++)
		{
			a[i]=0;
		}
		color(i);
	}
	for(int i=0;i<T;i++)
	{
		cout<<finans[i]<<endl;
	}
	return 0;
}
