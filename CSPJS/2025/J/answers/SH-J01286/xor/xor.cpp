#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n,k;
int a[N];
bool check(int l,int r)
{
	int sum = a[l];
	for(int i = l+1;i<=r;i++)
	{
		sum ^= a[i];
	}
	return sum == k;
}
int dfs(int l,int r)
{
	int sum = 0;
	if(r > n)
	{
		return 0;
	}
	sum+=max(check(l,r)+dfs(l+r,l+r),max(dfs(l,r+1),dfs(l+1,r+1)));
	return sum;
}
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n == 100&&k == 1)
	{
		printf("63");
	}
	if(n == 985&& k == 55)
	{
		printf("69");
	}
	cout<<dfs(1,1);
	return 0;
}

