#include<bits/stdc++.h>
using namespace std;
int fl[1001],n,k,a[1001],st,ed,mx;
void dfs(int step)
{
	int h;
	for(int i=st;i<=ed;i++)
	{
		h=a[i]^h;
	}
	if(h>mx)
	{
		mx=h;
	}
	if(st==ed)
		return;
	for(int i=step;i<=n;i++)
	{
		st=a[step];
		if(fl[i]==0)
		{
			ed=a[i];
			fl[i]=1;
			dfs(++step);
			fl[i]=0;
		}
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dfs(0);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
