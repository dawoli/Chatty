#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,ans,sum[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	int u;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&u);
		sum[u]++;
	}
	for(int i=1;i<N;i++)
	{
		int t=min(sum[i-1],sum[i]);
		ans+=t;
		sum[i-1]-=t;
		sum[i]+=sum[i-1];
	}	
	printf("%d\n",n-ans);
}
