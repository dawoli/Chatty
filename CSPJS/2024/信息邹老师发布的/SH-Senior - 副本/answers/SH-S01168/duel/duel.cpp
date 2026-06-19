#include<bits/stdc++.h>
using namespace std;
int n,maxn=0,minn=100005;
int a[100005];
bool f[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		a[t]++;
		maxn=max(maxn,t);
		minn=min(minn,t);
	}
	int ans=n;
	int sum=a[maxn];
	for(int i=maxn-1;i>=minn;i--)
	{
		if(a[i]!=0)
		{
			if(sum>=a[i])
			{
				ans=ans-a[i];
			}
			else
			{
				ans=ans-sum;
				sum=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
} 
