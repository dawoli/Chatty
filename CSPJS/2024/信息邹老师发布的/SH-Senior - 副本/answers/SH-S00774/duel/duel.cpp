#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int a[100005] = {};//剩余个数 
	int b[100005] = {};//可以攻击 
	int s;
	int minn = 100005,maxn = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		a[s]++;
		b[s]++;
		minn = min(minn,s);
		maxn = max(maxn,s);
	}
	for(int i=minn+1;i<=maxn;i++)
	{
		if(a[i]==0)
			continue;
		else
		{
			for(int j=minn;j<i;j++)
			{
				if(a[j]==0) continue;
				if(a[j]>=b[i])
				{
					a[j]-=b[i];
					b[i]=0;
				}
				else
				{
					b[i]-=a[j];
					a[j]=0;
				}
				if(b[i]==0)
					break;
			}
		}
	}	
	int ans = 0;
	for(int i=minn;i<=maxn;i++)
	{
		ans+=a[i];
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
