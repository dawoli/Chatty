#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,m,aa[N],c[N],T,X[4],a[N];
char s[N*2];
bool chart[20][N];
int lg_2(int x,int& now) {
	int y=0; now=1;
	while (now<x) now*=2, y++;
	return y;
}
bool ok[N*2];
long long solve(int c) {
	if (T==3) return 5;
	if (T==2) return 19;
	if (T==1) return 7;
	if (T==0) return 1;
	return -1;
/*
	int v, v1=1; int k=lg_2(c,v);
	for (int i=1;i<=v;i++) ok[i]=true;
	for (int i=1;i<=k;i++,v/=2,v1*=2)
		for (int j=0;j<v/2;j++)
			if (chart[i][j]) {
				bool flag=false;
				for (int now=2*j*v1+v1+1; now<=2*j*v1+2*v1; now++)
					if (ok[now] && )
				2*j*v1+1 ~ 2*j*v1+v1, 2*j*v1+v1+1 ~ 2*j*v1+2*v1
			}
	*/
}
long long work() {
	long long ans=0;
	for (int i=1;i<=m;i++)
		ans+=solve(c[i])*i;
	return ans;
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&aa[i]);
	for (int i=1;i<=m;i++) scanf("%d",&c[i]);
	int v; int K=lg_2(n,v);
	for (int i=1;i<=K;i++,v/=2) {
		scanf("%s",s);
		for (int j=0;j<v;j++) chart[i][j]=(s[j]=='1');
	}
	scanf("%d",&T);
	while (T--) {
		for (int i=0;i<4;i++) scanf("%d",&X[i]);
		for (int i=1;i<=n;i++) a[i]=aa[i]^X[i%4];
		printf("%lld\n",work());
	}
	return 0;
}
