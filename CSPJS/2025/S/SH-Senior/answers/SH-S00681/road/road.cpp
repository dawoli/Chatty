#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ___ __int128
using namespace std;
const int N=1e4+15,M=2e6+5;

inline ll read() {
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int n,m,k,cnt,c[15],f[N];
bool is[15];
ll ans=-1;
struct edge {
	int u,v,w,id;
} E[M];

int getf(int u) {
	return u==f[u]?u:f[u]=getf(f[u]);
}

void kru(int kk) {
	int ca=0;ll sum=0;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=cnt;i++) {
		if(ca==n+kk-1)break;
		int u=E[i].u,v=E[i].v,w=E[i].w,id=E[i].id;
		if(getf(u)==getf(v)||is[id]==0)continue;
		sum+=w;f[f[u]]=v;ca++;
	}
	for(int i=1;i<=k;i++)if(is[i])sum+=c[i];
	if(ans==-1)ans=sum;
	else ans=min(ans,sum);
}

void dfs(int step,int sum) {
	if(step==k) {
		kru(sum);
		return;
	}
	for(int i=0;i<=1;i++) {
		is[step+1]=i;
		if(i==1)sum++;
		dfs(step+1,sum);
	}
}

bool cmp(edge x,edge y) {
	return x.w<y.w;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) {
		int u,v,w;
		u=read();v=read();w=read();
		E[++cnt].u=u;
		E[cnt].v=v;
		E[cnt].w=w;
		E[cnt].id=0;
	}
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) {
			E[++cnt].u=n+i;
			E[cnt].v=j;
			E[cnt].w=read();
			E[cnt].id=i;
		}
	}
	is[0]=1;
	sort(E+1,E+cnt+1,cmp);
	dfs(0,0);
	cout<<ans;
	return 0;
}
