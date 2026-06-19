#include <bits/stdc++.h>
#define LL long long
inline int read() {
	char op=getchar();
	int w=1;
	while(op<'0'||op>'9') {
		if(op=='-') w=-1;
		op=getchar();
	}
	int as=0;
	while(op>='0'&&op<='9') {
		as=as*10+op-'0';
		op=getchar();
	}
	return w*as;
}
int T,N,a[200009];
#define INF_LL 0x3f3f3f3f3f3f3f3f
LL vq[1000009];
signed main(void) {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	while(T--) {
		N=read();
		for(int i=1;i<=N;i++) a[i]=read();
		LL ma=0;
		for(int i=1;i<=1000000;i++) vq[i]=-INF_LL;
		LL laz=0;
		for(int i=2;i<=N;i++) {
			LL as=std::max(vq[a[i]]+a[i],ma)+laz;
			laz+=((a[i]==a[i-1])?a[i]:0);
			vq[a[i-1]]=std::max(vq[a[i-1]],as-laz);
			ma=std::max(ma,as-laz);
		}
		printf("%lld\n",ma+laz);
	}
}
