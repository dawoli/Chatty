#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],l,f,fl[5001],mx,mn,st;

void dfs(int step)
{
	if(step>=3 && step<=n)
	{
		for(int i=0;i<step;i++)
		{
			if(fl[i]==1)
			{
				if(mx<a[i])
				{
					mx=a[i];
				}
			}
		}
		if(l>mx*2)
		{
			f++;
			mx=0;
		}
	}
	for(int i=step;i<=n;i++)
	{
		if(fl[i]==0)
		{
			l+=a[i];
			fl[i]=1;
			dfs(++step);
			fl[i]=0;
			l-=a[i];
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{ 
		cin>>a[i];
	}
	dfs(0);
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
