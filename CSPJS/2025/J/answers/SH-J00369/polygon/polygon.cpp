#include<bits/stdc++.h>
using namespace std;
int arr[5005],sum[5005],n,cnt;
int arr1[55];
map<int,int> mp;
void dfs(int layer,int sum,int maxv,int ans)
{
	int k,i;
	cnt=max(cnt,ans);
	if(sum>2*maxv)
	{
		cnt++;
		return;
	}
	if(layer>n)
		return ;
	layer++;
	arr1[layer]=layer;
	sum+=arr[layer];
	k=maxv;
	maxv=max(maxv,arr[layer]);
	dfs(layer,sum,maxv,ans);
	sum-=arr[layer];
	arr1[layer]=0;
	maxv=k;
	dfs(layer,sum,maxv,ans);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+1+n);
	for(i=1;i<=n;++i)
		sum[i]=sum[i-1]+arr[i];
	if(n<=20)
	{
		dfs(0,0,0,0);
		if(sum[n]>=arr[n]*2)
			printf("%d",cnt+1);
		else
			printf("%d",cnt);
		return 0;
	}
	else
	{
		
	}
	return 0;
}
