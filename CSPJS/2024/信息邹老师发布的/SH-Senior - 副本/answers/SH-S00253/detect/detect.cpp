#include <bits/stdc++.h>
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
struct n_t{
	int l,r;
} op[100009],op2[100009]; 
int v[1000009],vq[1000009],seg[4000009],a[200009];
int T,N,M,L,V;
#define ls (n<<1)
#define rs ((n<<1)|1)
#define md ((l+r)>>1)
#define INF 0x3f3f3f3f
void build(int n,int l,int r) {
	seg[n]=INF;
	if(l==r) {
		return;
	}
	build(ls,l,md),build(rs,md+1,r);
}
void up(int n,int l,int r,int p,int v) {
	seg[n]=std::min(seg[n],v);
	if(l==r) return;
	if(p<=md) up(ls,l,md,p,v);else up(rs,md+1,r,p,v);
}
void er(int n,int l,int r,int p) {
	if(l==r) {
		seg[n]=INF;
		return;
	} 
	if(p<=md) er(ls,l,md,p);else er(rs,md+1,r,p);
	seg[n]=std::min(seg[ls],seg[rs]);
} 
signed main(void) {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--) {
		int ct=0;
		N=read();M=read();L=read();V=read();
		for(int i=1;i<=N;i++) {
			int d=read(),v=read(),s=read();
			if(s==0) {
				if(v>V) {
					op[++ct]=(n_t){d+1,L+1};
				}
				continue;
			}
			if(s>0) {
				if(v>V) {
					op[++ct]=(n_t){d+1,L+1};					
					continue;
				}
				long long di=(1ll*V*V-1ll*v*v)/(2*s)+1;
				if(di+d>L) continue;
				op[++ct]=(n_t){di+d+1,L+1};				
			} else {
				if(v<=V) continue;
				long long di=(1ll*v*v-1ll*V*V-2*s-1)/(-2*s)-1;
				di+=d;
				if(di>L) di=L;
				op[++ct]=(n_t){d+1,di+1};
			}
		} 
		L++;
		for(int i=1;i<=L;i++) vq[i]=0,v[i]=0;
		for(int i=1;i<=M;i++) v[read()+1]++;
		for(int i=1;i<=L;i++) v[i]+=v[i-1];
		int ct2=0;
		for(int i=1;i<=ct;i++) {
			if(v[op[i].l-1]!=v[op[i].r]) {
				ct2++;
				vq[op[i].r]=std::max(vq[op[i].r],op[i].l);
			}
		}
		printf("%d ",ct2);
		for(int i=1;i<=L;i++) vq[i]=std::max(vq[i],vq[i-1]);
		build(1,0,L);
		up(1,0,L,0,0);
		int qd=0,cf=0;
		a[++qd]=0;
		for(int i=1;i<=L;i++) if(v[i]!=v[i-1]) a[++qd]=i;
		for(int i=1;i<=L;i++) {
			if(v[i]!=v[i-1]) {
				int as=seg[1];
				up(1,0,L,i,as+1);
			}
			while(cf<qd&&a[cf+1]<vq[i]) {
				cf++;
				er(1,0,L,a[cf]);
			}
		}
		printf("%d\n",M-seg[1]);
	}
} 
