#include<bits/stdc++.h>
#define HohleFeuerwerke using namespace std
//#pragma GCC optimize(3)
#define double long double
#define int long long
HohleFeuerwerke;
inline int read(){
	int s=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
const int MAXN=1e5+5;
int T,n,m,L,V,ans1,ans2,p[MAXN];
struct car{
	int d,v,a;
	int l,r;
}x[MAXN],tmp[MAXN];
//n cars; m testers; L length; V max_velocity
inline bool cmp(int a,int b){return a<b;}
inline void input(){
	n=read(),m=read(),L=read(),V=read();
	for(int i=1;i<=n;i++) x[i].d=read(),x[i].v=read(),x[i].a=read();
	for(int i=1;i<=m;i++) p[i]=read();
	sort(p+1,p+m+1,cmp);
}
inline bool judg(int p,car C){
	if(p<C.d) return false;
	else if(C.v*C.v+2*C.a*(p-C.d)<0) return false;
	else if(C.v*C.v+2*C.a*(p-C.d)>V*V) return true;
	else return false;
}
inline double ovpl(car C){
	double delta_x=(V*V-C.v*C.v+0.)/(2.*C.a);
	return delta_x+C.d;
}
inline int find(double x){
	int l=1,r=m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(x>p[mid]) l=mid+1;
		else r=mid-1;
	}
	return l;
}
inline bool cmp2(car A,car B){
	if(A.l<B.l) return 1;
	if(A.l>B.l) return 0;
	else return A.r<B.r;
}
inline void imit(){
	for(int i=1;i<=MAXN-5;i++) tmp[i].l=0,tmp[i].r=0;
	ans1=0,ans2=0; 
	for(int i=1;i<=n;i++){
		if(!x[i].a){
			if(x[i].v>V) x[i].l=find(x[i].d),x[i].r=m;
			else x[i].l=0,x[i].r=0;
		}
		else if(x[i].a>0){
			if(ovpl(x[i])>=p[m]) x[i].l=0,x[i].r=0;
			else{
				x[i].l=find(ovpl(x[i])),x[i].r=m;
				while(!judg(p[x[i].l],x[i])) x[i].l++;
			}
		}
		else if(x[i].a<0){
			if(x[i].v<=V) x[i].l=0,x[i].r=0;
			else{
				x[i].l=find(x[i].d),x[i].r=find(ovpl(x[i]));
				if(!judg(p[x[i].l],x[i])) x[i].l++;
				if(!judg(p[x[i].r],x[i])) x[i].r--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(x[i].r-x[i].l>=0&&x[i].r!=0) ans1++,tmp[ans1]=x[i];
	}
	if(ans1==0){ans2=m;return;}
	sort(tmp+1,tmp+ans1+1,cmp2);
	for(int i=1;i<=n;i++){
		int j=i,TOTR=tmp[i].r;
		while(TOTR>=tmp[j+1].l&&j+1<=n){
			j++,TOTR=min(tmp[j].r,TOTR);
		}
		ans2++,i=j;
	}
	ans2=m-ans2;
}
signed main()
{
	//原来TL是2s给我吓傻了！！！！！
	//大样例强度感觉还行
	//查了好几个边界问题出来
	//希望别fst 
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--){
		input();
		imit();
		printf("%lld %lld\n",ans1,ans2);
	}
}
