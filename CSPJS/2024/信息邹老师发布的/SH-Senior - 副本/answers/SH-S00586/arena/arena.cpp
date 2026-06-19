#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5,K=30;
int T;
int n,m,k,lbk;
int a[N],aa[N],X[10];//aa=a',
int c[N];
int d[K][N];
int win[4*N],tot[4*N];
ll ans[N];
//ch,x,ans1,ans2
ll sum(int l,int r) {
	return (l+r)*(r-l+1)/2;
}
void add(int p,int l,int r,int x,int R,int G) {
//	cout << p << ' ' << l << ' ' << r << ' ' << x<< endl;
	if(l==r) {
		win[p]=x;
		tot[p]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(p*2,l,mid,x,R-1,2*G-1);
	else add(p*2+1,mid+1,r,x,R-1,2*G);
	if(win[p*2]!=0&&win[p*2+1]!=0) {
		if(d[R][G]==0) {
			if(a[win[p*2]]>=R) win[p]=win[p*2];
			else win[p]=win[p*2+1];
		}
		else {
			if(a[win[p*2+1]]>=R) win[p]=win[p*2+1];
			else win[p]=win[p*2];
		}
	}
	tot[p]=tot[p*2]+tot[p*2+1];
}
bool queryl(int p,int l,int r,int x,int R,int G) {// < and x>=1
	if(tot[p]==0) return true;
	if(win[p]!=0) {
		if(a[win[p]]<x) return true;
		else return false;
	}
	int mid=(l+r)>>1;
	if(d[R][G]==0) {
		if(win[p*2]!=0) {
			if(a[win[p*2]]>=R) {
				if(a[win[p*2]]<x) return true;
				else return false;
			}
			else return true;
		}
		else {
			return queryl(p*2,l,mid,x,R-1,2*G-1);
		}
	}
	else return true;
}
ll querym(int p,int l,int r,int x,int R,int G) {// >=
//	cout << "qm" << p << ' ' << l << ' ' << r << ' ' << x << ' ' << R << ' ' << G<< endl;
	if(tot[p]==0) return sum(l,r);
	if(win[p]!=0) {
		if(a[win[p]]>=x) return win[p];
		else return 0;
	}
	int mid=(l+r)>>1;
	if(d[R][G]==0) {
		if(win[p*2]!=0) {
			if(a[win[p*2]]>=R) {
				if(a[win[p*2]]>=x) return win[p*2];
				else return 0;
			}
			else {
				return querym(p*2+1,mid+1,r,x,R-1,2*G);
			}
		}
		else {
			ll ans1=querym(p*2,l,mid,x,R-1,2*G-1);
			if(queryl(p*2,l,mid,R,R-1,2*G-1)) {
				ll ans2=sum(mid+1,r);
				return ans1+ans2;
			}
			else {
				return ans1;
			}
		}
	}
	else {
		if(tot[p*2+1]==0) {
			ll ans1=querym(p*2,l,mid,x,R-1,2*G-1);
			ll ans2=sum(mid+1,r);
			return ans1+ans2;
		}
		else {
			ll ans1;
			if(a[win[p*2]]>=R) {
				if(a[win[p*2]]>=x) ans1=win[p*2];
				else ans1=0;
			}
			else ans1=0;
			ll ans2=querym(p*2+1,mid+1,r,x,R-1,2*G);
			if(queryl(p*2+1,mid+1,r,R,R-1,2*G)) {
				return ans1+ans2;
			}
			else {
				return ans2;
			}
		}
	}
}
ll query(int p,int l,int r,int x,int R,int G) {
//	cout << "q" << p << ' ' << l << ' ' << r << ' ' << x << ' ' << R << ' ' << G<< endl;
	if(l==r) {
		return l;
	}
	int mid=(l+r)>>1;
	if((1<<x)<=mid) return query(p*2,l,mid,x,R-1,2*G-1);
	if(d[R][G]==0) {
//		cout << "yes\n";
		if(a[win[p*2]]>=R) return win[p*2];
		else return query(p*2+1,mid+1,r,x,R-1,2*G);
	}
	else {
		bool ans1=queryl(p*2+1,mid+1,r,x,R-1,2*G);
		ll ans2=querym(p*2+1,mid+1,r,x,R-1,2*G);
//		cout << "no " << ans1<< ' ' << ans2 << endl;
		if(!ans1) return ans2;
		else return win[p*2]+ans2;
	}
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&aa[i]);
	}
	for(int i=1;i<=m;i++) {
		scanf("%d",&c[i]);
	}
	while((1<<lbk)<n) {
		lbk++;
	}
	k=(1<<lbk);
	char ch;
	scanf("%c",&ch);
	for(int i=1;i<=lbk;i++) {
		for(int j=1;j<=(1<<(lbk-i));j++) {
			scanf("%c",&ch);
			if(ch=='1') d[i][j]=1;
		}
		scanf("%c",&ch);
	}
	scanf("%d",&T);
	while(T--) {
		memset(win,0,sizeof(win));
		memset(tot,0,sizeof(tot));
		for(int i=0;i<=3;i++) {
			scanf("%d",&X[i]);
		}
		for(int i=1;i<=n;i++) {
			a[i]=aa[i]^X[i%4];
		}
		// cal all ans[i], i from 1-m
		int ck=1,lbck=0;
		for(int i=1;i<=n;i++) {
			if(i>ck) {
				ck*=2;
				lbck++;
			}
			add(1,1,k,i,lbk,1);
//	cout << i << "a\n";
			ans[i]=query(1,1,k,lbck,lbk,1);
//	cout << i << ' ' << ans[i] << " q\n";
		}
		// cout
		ll cnt=0;
		for(ll i=1;i<=m;i++) {
			cnt^=(ans[c[i]]*i);
//			cout << cnt << endl;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

