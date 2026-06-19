#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ok[5005];
int n,cnt2=0;
void dfs(int idx,int last,int num)
{
	if(idx==num+1)
	{
		int sum = 0,maxx=-1;
		for(int j = 1;j<=num;j++)
		{
			sum+=ok[j];
			maxx=max(maxx,ok[j]);
		}
		if(sum>(2*maxx))
		{
			cnt2++;
		}
		return;
	}
	for(int i = last;i<=n;i++)
	{
		ok[idx+1]=a[i];
		dfs(idx+1,i,num);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int cnt1;
	for(int i = 3;i<=n;i++)
	{
		cnt2=0;
		dfs(0,0,i);
		cnt1+=cnt2;
	}
	cout << cnt1% 998244353;
	return 0;
}
