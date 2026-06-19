#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N];
int n;
int cnt=0;
int f=0;
void dfs(int step,int maxn,int sum)
{
	if(sum>2*maxn)
	{
		cnt++;
	}
	if(step>n)return;
	dfs(step+1,maxn,sum);
	dfs(step+1,a[step],sum+a[step]);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		int maxn=max(a[1],max(a[2],a[3]));
		int minn=min(a[1],min(a[2],a[3]));
		int mid=a[1]+a[2]+a[3]-maxn-minn;
		if(maxn<mid+minn)cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<cnt-2;
	return 0;

}
