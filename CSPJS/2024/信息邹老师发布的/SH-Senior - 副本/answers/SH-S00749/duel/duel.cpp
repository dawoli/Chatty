#include<bits/stdc++.h>
using namespace std;
int n,r[100003],ls[100003],ans,p,u;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&r[i]);
	for(int i = 1;i<=n;i++) ls[r[i]] += 1;
	for(int i = 1;i<=100000;i++) ls[i] += ls[i-1];
	ans = n;p = 0;u = 0;
	for(int i = 1;i<=100000;i++)
	{
		int k = min(u,min(p,ls[i]-p));
		ans -= k;
		u -= k;
		p += ls[i]-ls[i-1];
		u += ls[i]-ls[i-1];
	}
	printf("%d",ans);
	return 0;
}
