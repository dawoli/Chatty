#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
const int N = 1e5+7;
int LOG2[N];
ll read(){
	bool flag=0;
	ll res=0;
	char ch=std::getchar();
	while(ch>='0'&&ch<='9'||ch=='-'){
		if(ch=='-')flag=1;
		else res=(res<<3)+(res<<1)+(ch-'0');
		ch=std::getchar();
	}
	return (flag?(-res):res);
}
struct Car{
	ll a,v,d;
}arr[N];
int n,m;
ll L,V;
ll p[N];
bool isSpeed[N];
ll sqr(ll x){
	return x*x;
}
struct Seg{
	int l,r;
}Query[N];
int cntSeg=0;
bool chkSpeed(int i,int j){
	return sqr(arr[i].v)+2*arr[i].a*(p[j]-arr[i].d)<=sqr(V);
}
bool cmp(const Seg&A,const Seg&B){
	return A.r<B.r||A.r==B.r&&A.l>B.l;
}
void solve(){
	std::memset(arr,0,sizeof(arr));
	std::memset(isSpeed,0,sizeof(isSpeed));
	std::memset(p,0,sizeof(p));
	std::memset(Query,0,sizeof(Query));
	cntSeg=0;
	n=read();
	m=read();
	L=read();
	V=read();
	for(int i=1;i<=n;++i){
		arr[i].d=read();
		arr[i].v=read();
		arr[i].a=read();
	}
	for(int i=1;i<=m;++i)p[i]=read();
	int ans1=0;
	for(int i=1;i<=n;++i){
		if(arr[i].d>p[m])continue;
		if(arr[i].a==0){
			isSpeed[i]=(arr[i].v>V);
		}else if(arr[i].a>0){
			isSpeed[i]=(sqr(arr[i].v)+arr[i].a*(p[m]-arr[i].d)*2>sqr(V));
		}else{
			ll pos=*std::lower_bound(p+1,p+m+1,arr[i].d);
			isSpeed[i]=(sqr(arr[i].v)+arr[i].a*(pos-arr[i].d)*2>sqr(V));
		}
	}
	for(int i=1;i<=n;++i)if(isSpeed[i]){
		++ans1;
		if(arr[i].a==0){
			Query[++cntSeg]=(Seg){std::lower_bound(p+1,p+1+m,arr[i].d)-p,m};
		}else if(arr[i].a>0){
			int nowPos=std::lower_bound(p+1,p+1+m,arr[i].d)-p;
			int tmp=m;
			for(int j=LOG2[m-nowPos];j>=0;--j)if(!chkSpeed(i,tmp-(1<<j)))tmp-=1<<j;
			Query[++cntSeg]=(Seg){tmp,m};
//			std::printf("%d %d\n",tmp,m);
		}else{
			int nowPos=std::lower_bound(p+1,p+1+m,arr[i].d)-p;
			int tmp=nowPos;
			for(int j=LOG2[m-nowPos];j>=0;--j)if(!chkSpeed(i,tmp+(1<<j)))tmp+=1<<j;
			Query[++cntSeg]=(Seg){nowPos,tmp};
		}
	}
	std::sort(Query+1,Query+1+cntSeg,cmp);
//	for(int i=1;i<=n;++i)std::printf("%lld %lld %lld\n",arr[i].d,arr[i].v,arr[i].a);
//	for(int i=1;i<=cntSeg;++i)std::printf("%d %d\n",Query[i].l,Query[i].r);
	int ans2=0,nowR=0; 
	for(int i=1;i<=cntSeg;++i){
		if(Query[i].l>nowR){
			nowR=Query[i].r;
			++ans2;
		}
	}
	std::printf("%d %d\n",ans1,m-ans2);
}
void init(){
	LOG2[1]=0;
	for(int x=2;x<N;++x)LOG2[x]=LOG2[x>>1]+1;
}
int main(){
	std::freopen("detect.in","r",stdin);
	std::freopen("detect.out","w",stdout);
	init();
	int T;
	T=read();
	while(T--)solve();
	return 0;
}
