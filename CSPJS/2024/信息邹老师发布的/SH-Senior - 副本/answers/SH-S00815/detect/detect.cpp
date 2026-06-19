#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+20;
int n,m;
ll MAXL,V;
struct node{ll L,R;}e[N];
int ni,nd;
bool cmp(node x,node y){
	if(x.R==y.R)
		return x.L>y.L; 
	return x.R<y.R;
}
ll p[N];
int c[N*10];
bool vis[N];
int lb(int x){return x&(-x);}
void add(int x,int v){
	for(;x<N*10;x+=lb(x))
		c[x]+=v;
}
int sum(int x){
	int ret=0;
	while(x){
		ret+=c[x];
		x-=lb(x);
	}	
	return ret;
}
inline ll read(){
	char ch=getchar();
	ll ret=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void multi_test(){
	scanf("%d%d%lld%lld",&n,&m,&MAXL,&V);
	int cn=0;
	for(int i=1;i<=n;++i){
		ll d,v0,a;
		d=read(),v0=read(),a=read();
		if(a>0){
			ll L=0,R=0;
			if(v0>V)	L=d;
			else		L=d+(V*V-v0*v0)/(2*a)+1;
			R=MAXL;
			if(L>MAXL) continue;
			e[++cn]=(node){L,R};
//			cout<<"i="<<i<<endl;
		}
		if(a<0){
			ll L=0,R=0;
			if(v0>V)	L=d;
			else		L=MAXL+1;
			R=d+(v0*v0-V*V)/(2*(-a));
			if((v0*v0-V*V)%(2*(-a))==0)
				R--;
			R=min(R,MAXL);
			if(L>MAXL) continue;
			e[++cn]=(node){L,R};
//			cout<<"i="<<i<<endl;
		}
		if(a==0)
			if(v0>V)	e[++cn]=(node){d,MAXL};//,cout<<"i="<<i<<endl;
	}
	n=cn;
//	for(int i=1;i<=n;++i)
//		cout<<"**"<<e[i].L<<" "<<e[i].R<<endl;
	for(int i=1;i<=m;++i) p[i]=read(),p[i]++; 
	p[++m]=(int)1e7;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;++i) e[i].L++,e[i].R++; 
	int cnt_car=0,cur=0;
	for(int i=1;i<=n;++i){
		int l=e[i].L,r=e[i].R;
		int c=sum(r)-sum(l-1);
		if(c>0){
			cnt_car++;
			continue;
		}
		int w=upper_bound(p+1,p+m+1,r)-p-1;
		assert(p[w]<=r&&p[w+1]>r);
		if(w==m||w==0) continue;
		if(p[w]<l||p[w]>r) continue;
		vis[w]=1;add(p[w],1); cur++;	
		cnt_car++;
	} 
	cout<<cnt_car<<" "<<(m-1)-cur<<endl;
	for(int i=0;i<=m;++i){
		if(vis[i]) add(p[i],-1);
		vis[i]=0;
	}
	return;
} 
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--) multi_test();
	return 0;
}
