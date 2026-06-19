#include <bits/stdc++.h>
#define LL long long
inline int read() {
	char op=getchar();
	while(op<'0'||op>'9') {
		op=getchar();
	}
	int as=0;
	while(op>='0'&&op<='9') {
		as=as*10+op-'0';
		op=getchar();
	}
	return as;
}
int K,w[300009],N,M,aa[200009],c[100009],T,X[4],q[100009];
bool op[300009],s[20][200009];
char a[200009];
#define md ((l+r)>>1)
#define ls (n<<1)
#define rs ((n<<1)|1)
void sv(int n,int l,int r,int lv) {
	if(l==r) {
		return;
	}
	sv(ls,l,md,lv-1),sv(rs,md+1,r,lv-1);
	if(r<=N) {
		if(op[n]==0) {
			if(a[w[ls]]>=lv) w[n]=w[ls];else w[n]=w[rs];
		} else {
			if(a[w[rs]]>=lv) w[n]=w[rs];else w[n]=w[ls];			
		}
	} else w[n]=0;
}
void svv(int n,int l,int r,int lv) {
	if(l==r) {
		if(l<=N) w[n]=l;
		else w[n]=0;
		return;
	}
	op[n]=s[lv][l/(1<<lv)];
	svv(ls,l,md,lv-1),svv(rs,md+1,r,lv-1);
}
LL su;char mi,ma,lv,win;int x;
void sv2(int n,int l,int r) {
	if(x==r) {
		su+=((a[w[n]]>=win)?w[n]:0);
		mi=ma=a[w[n]];
		return;
	} 
	LL sm=su;
	if(x>md) {
		if(op[n]==0) {
			if(a[w[ls]]>=lv) {
				su+=((a[w[ls]]>=win)?w[ls]:0);
				mi=ma=a[w[ls]];return;
			}
			lv--;
			sv2(rs,md+1,r);
			lv++;
			return;
		}
		win=((win==0)?lv:win);lv--;
		sv2(rs,md+1,r);
		lv++;win=((win==lv)?0:win);
		if(mi>=lv) return;
		if(ma<lv) {
			mi=ma=a[w[ls]];
			su=sm+((a[w[ls]]>=win)?w[ls]:0);
			return;
		}
		mi=std::min(lv,a[w[ls]]);
		ma=std::max(ma,a[w[ls]]);
		su+=((a[w[ls]]>=win)?w[ls]:0);
	} else {
		if(op[n]==1) {
			lv--;
			sv2(ls,l,md);		
			lv++;
			mi=std::min(mi,lv);
			ma=K;
			su+=1ll*(r+md+1)*(r-md)/2; 
			return;				
		}
		win=((win==0)?lv:win);lv--;
		sv2(ls,l,md);
		lv++;win=((win==lv)?0:win);
		if(mi>=lv) return; 
		if(ma<lv) {
			su=sm+1ll*(r+md+1)*(r-md)/2;
			mi=0;ma=K;
			return;
		}
		mi=0;ma=K;
		su+=1ll*(r+md+1)*(r-md)/2;
	}
}
signed main(void) {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	N=read();M=read();
	for(int i=1;i<=N;i++) {
		aa[i]=read();
	}
	for(int i=1;i<=M;i++) {
		c[i]=read();
		q[i]=0;
		while((1<<q[i])<c[i]) q[i]++;
	}
	K=1;
	while((1<<K)<N) {
		K++;
	}
	for(int i=1;i<=K;i++) {
		char op=getchar();
		while(op<'0'||op>'1') op=getchar();
		for(int j=0;j<(1<<K-i);j++) {
			s[i][j]=op-'0';
			op=getchar();
		}
	}
	svv(1,1,(1<<K),K);
	int n=1,l=1,r=(1<<K);
	while(l<r) {
		if(op[n]==0) n=ls,r=md;else n=rs,l=md+1;
	}
	int id=l;
	T=read();
	while(T--) {
		for(int i=0;i<4;i++) X[i]=read();
		for(int i=1;i<=N;i++) {
			if((aa[i]^X[i%4])>K) a[i]=K;
			else a[i]=(aa[i]^X[i%4]);
		}
		sv(1,1,(1<<K),K);
		LL as=0;
		for(int i=1;i<=M;i++) {
			if(id<=c[i]&&(a[id]>=K)) {
				as^=(1ll*a[id]*i);
				continue;
			}
			x=c[i]; 
			su=0;
			int n=(1<<K-q[i]),l=1,r=(1<<q[i]);lv=q[i];win=0;
			sv2(n,l,r);
			as^=(su*i);
		}
		printf("%lld\n",as);
	}
}
