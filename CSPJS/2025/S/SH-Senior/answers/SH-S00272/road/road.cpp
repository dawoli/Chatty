#include <bits/stdc++.h>
static char buf[1000009],*paa=buf,*pd=buf;
#define getchar() ((paa==pd&&(paa=buf,pd=paa+fread(buf,1,1000000,stdin),paa==pd))?(EOF):(*paa++))
int read() {
	int w=1,x=0;
	char op=getchar();
	while(op<'0'||op>'9') {
		if(op=='-') w=-1;
		op=getchar();
//		printf("%d\n",op);
	}
	while(op>='0'&&op<='9') {
		x=x*10+op-'0';
		op=getchar();
//		printf("%d\n",op);
	}
	return w*x;
}
struct n_t{
	int u,v,w;
} f[1000029],as[1025][10029],qq[1000029];
int N,M,K,pa[10029],c[12],a[12][10029],b[12][10029],id;
inline int fr(int x) {
	while(x!=pa[x]) x=pa[x]=pa[pa[x]];
	return x;
}
inline bool cmp(n_t x,n_t y) {
	return x.w<y.w;
}
inline bool cmpi(int x,int y) {
	return a[id][x]<a[id][y];
}
signed main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	N=read();M=read();K=read();
	for(int i=1;i<=M;i++) {
		f[i].u=read();
		f[i].v=read();
		f[i].w=read();
	}
	for(int i=1;i<=K;i++) {
		c[i]=read();
		for(int j=1;j<=N;j++) {
			a[i][j]=read();
			b[i][j]=j;
		}
		id=i;
		std::sort(b[i]+1,b[i]+N+1,cmpi);
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<(1<<K);i++) {
		int bb=0;
		if(i==0) {
			for(int j=1;j<=M;j++) {
				qq[++bb]=f[j];
			}
			std::sort(qq+1,qq+bb+1,cmp);
		} else {
			int xx=0;
			for(int j=1;j<=K;j++) {
				if((i>>j-1)&1) {
					xx=j;break;
				}
			}
			int num=N-2+__builtin_popcount(i);
			int pp=1,qqq=1;
			while(pp<=N||qqq<=num) {
				if(pp<=N&&(qqq>num||a[xx][b[xx][pp]]<=as[i-(1<<xx-1)][qqq].w)) {
					qq[++bb]=(n_t){xx+N,b[xx][pp],a[xx][b[xx][pp]]};
					pp++;
				} else {
					qq[++bb]=as[i-(1<<xx-1)][qqq];
					qqq++;
				}
			}
		}
		for(int j=1;j<=N+K;j++) {
			pa[j]=j;
		}
		int cc=0;
		long long aq=0;
		for(int j=1;j<=K;j++) if((i>>j-1)&1) aq+=c[j];
		for(int j=1;j<=bb;j++) {
			int aa=fr(qq[j].u),bb=fr(qq[j].v);
			if(aa!=bb) {
				aq+=qq[j].w;
				pa[aa]=bb;
				as[i][++cc]=qq[j];
			//	printf("%d %d %d %d\n",i,qq[j].u,qq[j].v,qq[j].w);
			}
		}
	//	printf("%d %lld\n",i,aq);
		ans=std::min(ans,aq);
	}
	printf("%lld\n",ans);
}
