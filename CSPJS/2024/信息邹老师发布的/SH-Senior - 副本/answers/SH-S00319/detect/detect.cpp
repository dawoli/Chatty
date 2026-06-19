#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N = 1e5+5;
int f,n,m,l,V,T,t[N*10],mx,d[N],v[N],a[N],p[N],ans1,ans2;
bool flag;
char c;
inline void add(int x,int k){for(int i=x;i<=l;i+=lowbit(i)) t[i]+=k;}
inline int sum(int k){int cnt=0; for(int i=k;i;i-=lowbit(i)) cnt+=t[i]; return cnt;}
inline void read(int &x){
	c=getchar(),x=0,f=1;
	while(c<'0'||c>'9'){
		f=((f>0)&(c=='-')?-1:f);
		c=getchar();
	}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	x=(f>0?x:-x);
} 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		read(n),read(m),read(l),read(V); mx=0;
//		mx=0,n=1e5,m=1e5,l=1e6,V=10; 
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;++i){
			read(d[i]),read(v[i]),read(a[i]);
//			d[i]=1,v[i]=1+rand()%1000,a[i]=0;
			if(v[i]>V) add(d[i],1);
		}
		for(int i=1;i<=m;++i){
			read(p[i]);
//			p[i]=rand()%l+1;
			mx=max(mx,p[i]);
		}
		ans1=ans2=0;
		printf("%d ",ans1=sum(p[m]));
		if(!ans1) ans2=m;
		else ans2=m-1;
		printf("%d\n",ans2);
	}
	return 0;
}
