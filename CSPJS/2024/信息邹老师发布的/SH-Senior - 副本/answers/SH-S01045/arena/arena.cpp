#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int S=1<<21;
char buf[S],*p1,*p2;
inline int nc(){
	if(p1==p2){
		p2=(p1=buf)+cin.read(buf,S).gcount();
		if(p1==p2)return EOF;
	}return *p1++;
}
inline int rd(){
	char ch;
	while(!isdigit(ch=nc()));
	int x=ch&0xf;
	while(isdigit(ch=nc()))x=x*10+(ch&0xf);
	return x;
}
constexpr int N=1e5+9,M=1<<17;
int n,m,h,w,_a[N],a[M],c[N],mxp[M],mxv[M],mnv[M],tog[M<<1];
bool st[M];
ll ans[M];
struct node{
	int winner,maxopt;
}zkw[M<<1];
node merge(node l,node r,int v){
	node x;
	x.winner=a[l.winner]>=v?l.winner:r.winner;
	if(l.winner>=r.winner)x.maxopt=l.maxopt;
	else if(a[l.winner]<v)x.maxopt=r.maxopt;
	else x.maxopt=l.maxopt;
	return x;
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	n=rd(),m=rd();
	for(int i=0;i<n;++i)_a[i]=rd();
	for(int i=0;i<m;++i)c[i]=rd();
	for(int s=w=1<<(h=__lg(n-1)+1);s>1;s>>=1)
	    for(int x=s>>1;x<s;++x){
	        char c;
			while(!isdigit(c=nc()));
			st[x]=c&1;	
	    }
	memset(a,0x3f,w*sizeof(int));
	for(int i=1;i<w;++i)mnv[i]=1<<__lg(i);
	for(int T=rd();T;--T){
		int xv[4];
		for(int i=0;i<4;++i)xv[i]=rd();
		for(int i=0;i<n;++i)a[i]=_a[i]^xv[(i+1)&3];
		for(int i=0;i<w;++i)zkw[i|w]={i,i};
	    for(int v=h;v;--v)
	        for(int i=1<<(v-1);i<(1<<v);++i)
		        zkw[i]=!st[i]?merge(zkw[i<<1],zkw[i<<1|1],h-v+1):merge(zkw[i<<1|1],zkw[i<<1],h-v+1);
		for(int i=(w<<1)-1;i;--i)mxp[zkw[i].winner]=i;
		for(int i=0;i<w;++i)
			mxv[i]=((mxp[i]&1)^st[mxp[i]>>1])?w-1:i-1;
		for(int i=2;i<(w<<1);++i)
		    if(zkw[i>>1].winner!=zkw[i].winner&&((i&1)^st[i>>1])){
		    	if(zkw[i].winner<zkw[i^1].winner)tog[i]=zkw[i^1].maxopt-1;
		    	else tog[i]=-1;
			}else tog[i]=w-1;
		for(int i=4;i<(w<<1);++i)tog[i]=min(tog[i],tog[i>>1]);
		for(int i=0;i<w;++i)mxv[i]=min(mxv[i],tog[i|w]);
		memset(ans,0,w*sizeof(ll));
		for(int i=0;i<w;++i){
			int l=mnv[i],r=mxv[i];
			if(l>r)continue;
			ans[l]+=i+1;
			if(r!=w-1)ans[r+1]-=i+1;
		}
		partial_sum(ans,ans+w,ans);
		ll res=0;
		for(int i=0;i<m;++i)res^=1ll*(i+1)*ans[c[i]-1];
		cout<<res<<'\n';
	}
	return cout<<flush,0;
}
