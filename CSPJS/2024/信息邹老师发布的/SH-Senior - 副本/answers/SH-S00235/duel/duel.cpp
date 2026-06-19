#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		a[t]++;
		maxn=max(maxn,t);
	}
	int sum=0;
	for(int i=1;i<=maxn;i++)
	{
		if(a[i]==0)
		{
			continue;
		}
		int h=max(0,sum-a[i]);
		sum=h+a[i];
	}
	cout<<sum<<endl;
	return 0;
}
