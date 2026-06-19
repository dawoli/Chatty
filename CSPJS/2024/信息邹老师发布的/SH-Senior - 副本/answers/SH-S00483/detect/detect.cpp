#include<bits/stdc++.h>
#define eps 1e-7
#define N 100009
#define P 1000009
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
inline ll read(){
	char c=getchar();ll x=0,f=1;
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
struct len{
    ll l,r,id;
    bool operator<(const len&y){
    	return l<y.l||(l==y.l&&r>y.r);
	}
} Len[N],Len2[N];
// l ~ r required 
ll T,n,m,V,L,tot1,tot2,p[N],TOT,d[P],s[P],res,TOT2,res2;
pair<double,double> c1[N],c2[N];
ll near(double x){
	if(ceil(x)-x<=0.001) return ceil(x);
	else return floor(x);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		tot1=tot2=TOT=res=TOT2=res2=0;
		for(int i=1;i<=L;i++) d[i]=s[i]=0;
		n=read(),m=read(),L=read()+1,V=read();
		for(int i=1,v,a,D;i<=n;i++){
			D=read()+1,v=read(),a=read();
			if(a>0){
				double l=D+(V*V-v*v)/2.0/a;
				if(l>=L) continue;
				c1[++tot1]=mp(max(D-eps,l+eps),L);
			}
			else if(a==0){
				if(v>V) c1[++tot1]=mp(D-eps,L);
			}	
			else if(a<0){
				if(v<=V) continue;
				double l=D+(V*V-v*v)/2.0/a;
				c2[++tot2]=mp(D,min(l-eps,L+eps));
			}
	    }
		for(int i=1;i<=m;i++) p[i]=read()+1,d[p[i]]++;
		for(int i=1;i<=L;i++) s[i]=s[i-1]+d[i];
		for(int i=1;i<=tot1;i++){
			ll p=ceil(c1[i].fi),q=near(c1[i].se);
			if(s[q]-s[p-1]>0) res++,Len[++TOT]=(len){p,q,TOT};
		}
		for(int i=1;i<=tot2;i++){
			ll p=near(c2[i].fi),q=floor(c2[i].se);
			if(s[q]-s[p-1]>0) res++,Len[++TOT]=(len){p,q,TOT};
		}
		printf("%lld ",res);
		sort(Len+1,Len+TOT+1);
		ll mnr=INF;
		for(int i=TOT;i>=1;i--){
			if(Len[i].r>=mnr) continue;
			mnr=Len[i].r,Len2[++TOT2]=Len[i];
		}
		sort(Len2+1,Len2+TOT2+1);
		ll lst=-1;
		for(int i=1;i<=TOT2;i++){
			if(lst>=Len2[i].l) continue;
			ll l=upper_bound(p+1,p+m+1,Len2[i].r)-p;
			lst=p[l-1],res2++;
		}
		printf("%lld\n",m-res2);
	}
	return 0;
}
//Defection
