#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO{
char ibuf;
int rd(int x=0)
{
	for(;!isdigit(ibuf);ibuf=getchar());
	for(;isdigit(ibuf);ibuf=getchar())x=(x<<1)+(x<<3)+(ibuf^48);
	return x;
}
}using IO::rd;//namespace IO
int a[100010];
int cnt[100010];
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	int ans=0;
	for(int i=1;i<=100000;i++)ans=max(ans,cnt[i]);
	printf("%lld\n",ans);
	return 0;
}