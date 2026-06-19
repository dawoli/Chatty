#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;

int st[N];

bool vis[N];

bool solve(int x,int y,int z)
{
	int mx;
	mx=max(x,max(y,z));
	if(x+y+z>2*mx)
	{
		return 1;
	}
	return 0;
}

long long sum(int l,int r)
{
	long long s=0;
	for(int i=l;i<=r;i++)
	{
		s+=st[i];
	}
}

//void dfs(int x)
//{
//	int use=0;
//	if(x==3)
//	{
//		return;
//	}
//	else
//	{
//		for(int i=1;i<=x;i++)
//		if(!vis)	
//		
//	}
//	
//	
//	
//}

//int st[N];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t,l,r;
	long long ans=0;
	cin>>t; 
	l=1;
	r=t;
	for(int i=1;i<=t;i++)
	{
		cin>>st[i];
	}
	if(t<=2)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);		
		return 0;
	}
	sort(st+1,st+t+1);
//	dfs(t);
	for(int i=l;i<=t;i++)
	{
		for(int j=i+1;j<=t;j++)
		{
			for(int k=j+1;k<=t;k++)
			{
				if(solve(st[i],st[j],st[k]))
				{
					ans++;
				}
			}
				
		}	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
/*
2 2
99 100 97 98
*/
