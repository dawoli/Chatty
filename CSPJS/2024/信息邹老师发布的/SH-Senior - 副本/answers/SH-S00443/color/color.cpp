#include<bits/stdc++.h>
using namespace std;
int n,arr[100005];
int m[100005];
long long ans;
long long check()
{
	long long ret=0;
	int i,prev1=0,prev2=0;
	for(i=1;i<=n;++i){
		if(m[i]==1&&arr[prev1]==arr[i])
			ret+=arr[i];
		else if(m[i]==2&&arr[prev2]==arr[i])
			ret+=arr[i];
		if(m[i]==1)
			prev1=i;
		else
			prev2=i;
	}
	return ret;
}
void dfs(int layer)
{
	if(layer>n)
	{
		ans=max(ans,check());
		return;
	}
	m[layer]=1;
	dfs(layer+1);
	m[layer]=2;
	dfs(layer+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int TTT;
	scanf("%d",&TTT);
	while(TTT--){
		ans=0;
		scanf("%d",&n);
		int i,j;
		for(i=1;i<=n;++i)
			scanf("%d",&arr[i]);
		dfs(1);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
