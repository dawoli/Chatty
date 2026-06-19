#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N],cnt[N],p=1,ans=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),a[i]=b[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	for(int i=1;i<=n;++i) cnt[a[i]]++;
	for(int i=2;i<=m;++i) {
		int x=cnt[i];
		while(p<i&&cnt[p]<=x) x-=cnt[p],cnt[p]=0,++p;
		if(p<i) cnt[p]-=x,x=0;
	}
	for(int i=1;i<=m;++i) ans+=cnt[i];
	printf("%d\n",ans);
	return 0;
}
