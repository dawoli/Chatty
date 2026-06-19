#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long a[500005];
long long xorsum[500005];
long long ans;

void dfs(int step,long long base,long long cur);

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i];
		xorsum[i] = a[i] xor xorsum[i-1];
		//cout<<xorsum[i]<<' ';
	}
	//cout<<endl;
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

void dfs(int step,long long base,long long cur)
{
	bool flag = false;
	if((xorsum[step] xor base) == k)
	{
		flag = true;
	}
	if (step == n)
	{
		if(flag)cur++;
		if (cur>ans) ans = cur;
		return;
	}
	if(flag)
	{
		dfs(step+1,xorsum[step],cur+1);
	}
	else
	{
		if(n<=30)dfs(step+1,xorsum[step],cur);
		dfs(step+1,base,cur);
	}
}
