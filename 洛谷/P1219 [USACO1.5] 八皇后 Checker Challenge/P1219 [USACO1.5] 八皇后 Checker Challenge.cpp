// Problem URL: https://www.luogu.com.cn/problem/P1219
// Finish Time: 2026/4/11 15:26:20 AC
// Start Time: 2026/4/11 11:13:28

#include<bits/stdc++.h>
using namespace std;
int ans[14],c[3][28],sum=0,n;
void dfs(int l)
{
	if(l>n)
	{
		sum++;
		if(sum>3)return;
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if((!c[0][i])&&(!c[1][l+i])&&(!c[2][l-i+n]))
		{
			ans[l]=i;
			c[0][i]=1; c[1][l+i]=1; c[2][l-i+n]=1;
			dfs(l+1);
			c[0][i]=0; c[1][l+i]=0; c[2][l-i+n]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	dfs(1);
	cout<<sum;
	return 0;
}