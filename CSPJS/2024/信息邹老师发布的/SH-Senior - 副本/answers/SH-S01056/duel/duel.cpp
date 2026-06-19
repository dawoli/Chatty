#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[100010],maxx;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
//		maxx=max(maxx,a);
		maxx=max(maxx,cnt[a]);
	}
//	for(int i=maxx;i>=1;i--)
//	{
//		if(cnt[i]-killed>0)
//		{
//			ans+=(cnt[i]-killed);
//			killed+=ans;
//		}
//	}
//	printf("%d",ans);
	printf("%d",maxx);
	return 0;
}
