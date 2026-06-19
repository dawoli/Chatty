#include <bits/stdc++.h>
int T,N,a[100009][4],bb[100009];
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
signed main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) {
		N=read();
		int ct[4]={0};
		long long su=0;
		for(int i=1;i<=N;i++) {
			int p=1;
			for(int j=1;j<=3;j++) {
				a[i][j]=read();
				if(a[i][p]<a[i][j]) {
					p=j;
				}
			}
			ct[p]++;
			su+=a[i][p];
		}
		int pp=0;
		for(int i=1;i<=3;i++) {
			if(ct[i]>N/2) {
				pp=i;
			}
		}
		if(pp==0) {
			printf("%lld\n",su);
			continue;
		}
		int qq=0;
		for(int i=1;i<=N;i++) {
			int p=1;
			for(int j=1;j<=3;j++) {
				if(a[i][p]<a[i][j]) {
					p=j;
				}
			}
			if(p==pp) {
				int aa=0x3f3f3f3f;
				for(int j=1;j<=3;j++) {
					if(j!=p) aa=std::min(aa,a[i][p]-a[i][j]);
				}
				bb[++qq]=aa;
			}
		}
		std::sort(bb+1,bb+qq+1);
		for(int i=1;i<=qq&&i<=ct[pp]-N/2;i++) su-=bb[i];
		printf("%lld\n",su);
	}
}