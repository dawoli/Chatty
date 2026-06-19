#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
#define pc(x) putchar(x)
inline int rd(){int x=0;bool f=0;char c=gc;while(c<48||c>57) c=='-'&&(f=1),c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return f?-x:x;}
inline int rdc(){char c=gc;while(c<48||c>57) c=gc;return c^48;}
inline void ot(ll x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
ll t,n,m,s,a[100009],c[100009],d[19][131079],x[4],w[19][131079],ans;
int main(){
	freopen("arena.in","r",stdin),freopen("arena.out","w",stdout);
	//#4,5,11,12(A性质)，n,m<=500来不急不写了 
	n=rd(),m=rd(),s=__lg(n-1)+1;
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1;i<=m;++i) c[i]=rd();
	for(int i=1;i<=s;++i) for(int j=1;j<=(1<<(s-i));++j) d[i][j]=rdc();
	t=rd();
	for(int i=0;i<4;++i) x[i]=rd();
	for(int i=1;i<=n;++i) a[i]^=x[i&3],w[0][i]=i;
	for(int i=1;i<=s;++i) for(int j=1;(j<<i)<=n;++j){
		ll u=w[i-1][j*2-1],v=w[i-1][j*2];
		if(d[i][j]) swap(u,v);
		w[i][j]=(a[u]>=i?u:v);
	}
	for(int i=1;i<=m;++i) ans^=(i*w[__lg(c[i])][1]);
	ot(ans),pc('\n');
	return 0;
}
