#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,m,L,V;
int d[N],v[N],a[N],p[N];

inline int sqrd(int a,int b) {
	return a*a-b*b;
}

struct seg {
	int l,r;
	inline bool operator<(const seg&b)const {
		return r<b.r||(r==b.r&&l<b.l);
	}
} s[N];

int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
//	freopen("detect.err","w",stderr);
	int T;
	T=read();
	while(T--) {
		n=read();
		m=read();
		L=read();
		V=read();
		for(int i=1; i<=n; ++i) {
			d[i]=read();
			v[i]=read();
			a[i]=read();
		}
		for(int i=1; i<=m; ++i) p[i]=read();
		sort(p+1,p+1+m);
		int cnt=0;
		for(int i=1; i<=n; ++i) {
			s[i]=seg({m+1,m+1});
			if(a[i]>0) {
				if(v[i]>V) {
					int b=lower_bound(p+1,p+1+m,d[i])-p;
					if(b<=m) {
						++cnt;
						s[i]=seg({b,m});
					}
				} else {
					int b=upper_bound(p+1,p+1+m,d[i]+sqrd(V,v[i])/(2*a[i]))-p;
					if(b<=m) {
						++cnt;
						s[i]=seg({b,m});
					}
				}
			} else if(a[i]==0) {
				if(v[i]>V) {
					int b=lower_bound(p+1,p+1+m,d[i])-p;
					if(b<=m) {
						++cnt;
						s[i]=seg({b,m});
					}
				}
			} else {
				if(v[i]>V) {
					int tmp=sqrd(V,v[i]),lim=d[i]+tmp/(2*a[i]);
					if((tmp/(2*a[i]))*(2*a[i])==tmp) --lim;
					int b1=lower_bound(p+1,p+1+m,d[i])-p;
					int b2=upper_bound(p+1,p+1+m,lim)-p;
					if(b1<=m&&b2>b1) {
						++cnt;
						s[i]=seg({b1,b2-1});
					}
				}
			}
		}
		sort(s+1,s+1+n);
		int ns=lower_bound(s+1,s+1+n,seg({m+1,m+1}))-s-1;
		int ans=0,pr=0;
		for(int i=1; i<=ns; ++i) {
			if(s[i].l>pr) pr=s[i].r,++ans;
		}
		cout<<cnt<<" "<<m-ans<<endl;
	}
	return 0;
}

