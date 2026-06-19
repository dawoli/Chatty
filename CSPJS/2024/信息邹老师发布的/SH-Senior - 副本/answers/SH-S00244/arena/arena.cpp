#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>='9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>10)write(x/10);
	putchar(x%10+'0');
}
void file(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
}
const ll N=100005,P=20;
ll a[N],x[N],t[N],c[N],LOG2[N],T,n,m;bool d[P][N],spA=1;
struct Segment{ll l,r,id,len;}tr[N*4];
void merge(ll u){
	ll r=LOG2[tr[u].len];
	ll v1=d[r][tr[u].l%tr[u].len]==0?u*2:u*2+1;
	ll v2=v1==u*2?u*2+1:u*2;
	if(a[tr[v1].id]>=r)tr[u].id=tr[v1].id;
	else tr[u].id=tr[v2].id;
}
void build(ll u,ll l,ll r){
	tr[u]=(Segment){l,r,0,r-l+1};
	if(l==r){tr[u].id=l;return;}
	ll mid=l+(r-l>>1);
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	merge(u);
}
ll query(ll u,ll x){
	if(tr[u].r==x)return tr[u].id;
	else return query(u<<1,x);
}
void solve_spA(){
	ll p=1<<LOG2[n];
	build(1,1,p);
	ll res=0;
	for(ll i=1;i<=m;i++)res^=(c[i]*query(1,c[i]));
	write(res),puts("");
}
int main(){
	file();
	n=read(),m=read();
	LOG2[0]=-1;
	for(ll i=1;i<=n;i++)LOG2[i]=LOG2[i>>1]+1;
	for(ll i=1;i<=n;i++)t[i]=read();
	for(ll i=1;i<=m;i++)c[i]=read(),spA&=LOG2[c[i]]==LOG2[c[i]-1]+1;
	for(ll r=0;r<=LOG2[n];r++,getchar())
		for(ll g=1;g<=(1<<(LOG2[n]-r));g++)
			d[r][g]=getchar()-'0';
	T=read();
	while(T--){
		for(ll i=1;i<=4;i++)x[i]=read();
		for(ll i=1;i<=n;i++)a[i]=t[i]^x[i%4];
		if(spA)solve_spA();
	}
	return 0;
}
