#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,cnt=0;
void dfs(int step,int num,int maxn,int sum)
{
	if (step>n)
	{
		if (num>2&&sum>maxn*2)cnt++;
		return;
	}
	dfs(step+1,num,maxn,sum);//no
	dfs(step+1,num+1,max(maxn,a[step]),sum+a[step]);//yes
}
int main()
{
	freopen("polygon5.in","r",stdin);
	freopen("polygon5.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<cnt<<endl;
}
