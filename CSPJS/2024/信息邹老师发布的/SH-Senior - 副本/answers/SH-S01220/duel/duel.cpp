#include<bits/stdc++.h>
#define HohleFeuerwerke using namespace std
#define int long long
HohleFeuerwerke;
inline int read(){
	int s=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
const int MAXN=1e5+5;
int n,ans,a[MAXN],brak[MAXN];
inline bool cmp(int a,int b){return a<b;}
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) brak[++cnt]++;
		else brak[cnt]++;
	}
	for(int i=1;i<=cnt;i++) ans=max(ans,brak[i]);
	printf("%lld\n",ans);
}
