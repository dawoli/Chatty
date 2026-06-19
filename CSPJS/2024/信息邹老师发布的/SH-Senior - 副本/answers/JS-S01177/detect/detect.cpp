#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int l,r;
}c[N],cc[N];
bool cmp(node x,node y){
	if(x.l==y.l) return x.r>y.r;
	else return x.l<y.l;
}
int n,m,l,mv;
int d[N],v[N],a[N];
int p[N];
int k=0,kk=0;
inline bool toofast(int v,int a,int s){
	if(s<0) return false;
	if(2ll*a*s+1ll*v*v>1ll*mv*mv) return true;
	return false;
}
inline int find_r(int x){
	int l=0,r=m;
	while(l+1<r){
		int mid=(l+r)/2;
		if(p[mid]>=x) r=mid;
		else l=mid;
	}
	return r;
}
inline int find_fl(int v,int a,int d){
	int l=0,r=m;
	while(l+1<r){
		int mid=(l+r)/2;
		if(toofast(v,a,p[mid]-d)) r=mid;
		else l=mid;
	}
	return r;
}
inline int find_fr(int v,int a,int d){
	int l=1,r=m+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(p[mid]<d||toofast(v,a,p[mid]-d)) l=mid;
		else r=mid;
	}
	return l;
}
inline void MAIN(){
	k=0;kk=0;
	scanf("%d%d%d%d",&n,&m,&l,&mv);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		if(d[i]>p[m]) continue;
		int fr=find_r(d[i]);
		if(a[i]>0){
			if(toofast(v[i],a[i],p[m]-d[i])) c[++k]={find_fl(v[i],a[i],d[i]),m};
		}
		else if(a[i]<0){
			if(toofast(v[i],a[i],p[fr]-d[i])) c[++k]={fr,find_fr(v[i],a[i],d[i])};
		}
		else if(v[i]>mv){
			c[++k]={fr,m};
		}

	}
	printf("%d ",k);
	sort(c+1,c+1+k,cmp);

	for(int i=1;i<=k;i++){
		while(kk&&cc[kk].r>=c[i].r) kk--;
		cc[++kk]=c[i];
	}
	int ll=0,pp=0;
	for(int i=1;i<=kk;i++){
		if(cc[i].l<=ll) continue;
		pp++;ll=cc[i].r;
	}
	printf("%d\n",m-pp);
	return;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
	while(t--) MAIN();
	return 0;
} 
