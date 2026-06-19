/*
f[i][j]是i涂蓝色,然后上一个涂红色的是j的最大权值
if(j+1==i)
	f[i][j]=max(f[k][j]+(a[k]==a[i])*a[i])
else
	f[i][j]=f[i-1][j]+(a[i-1]==a[i])*a[i]
f[i][j]=max(f[][j]
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Nm=2009;
const ll N=200009;
const ll V=1000009;
ll T,n,m,a[N],pre[N],ma,fBF[N],lst[N],pos[V],f[N];
int fBBF[Nm][Nm];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=((bool)(c^'-')<<1)-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
struct tree{ll l,r,ma,toAdd;}tr[4*N];
void buildST(ll x,ll l,ll r){
	tr[x]=(tree){l,r,0,0};
	if(l==r) return;
	ll mid=(l+r)>>1;
	buildST(x*2,l,mid);
	buildST(x*2+1,mid+1,r);
}
void pushdown(ll x){
	if(tr[x].toAdd){
		tr[x*2].toAdd+=tr[x].toAdd;
		tr[x*2].ma+=tr[x].ma;
		tr[x*2+1].toAdd+=tr[x].toAdd;
		tr[x*2+1].ma+=tr[x].ma;
		tr[x].toAdd=0;
	}
}
void add(ll x,ll l,ll r,ll V){
	if(tr[x].l>r||tr[x].r<l) return;
	if(l<=tr[x].l&&tr[x].r<=r){
		tr[x].toAdd+=V;
		tr[x].ma+=V;
		return;
	}
	pushdown(x);
	add(x*2,l,r,V);
	add(x*2+1,l,r,V);
	tr[x].ma=max(tr[x*2].ma,tr[x*2+1].ma);
}
ll query(ll x,ll l,ll r){
	if(tr[x].l>r||tr[x].r<l) return 0;
	if(l<=tr[x].l&&tr[x].r<=r) return tr[x].ma;
	pushdown(x);
	return max(query(x*2,l,r),query(x*2+1,l,r));
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	while(T--){
//		chu();
		memset(lst,0,sizeof(lst));
		memset(pos,0,sizeof(pos));
		n=read();
		for(ll i=1;i<=n;++i)
			a[i]=read(),ma=max(ma,a[i]),lst[i]=pos[a[i]],pos[a[i]]=i;
		if(n<=2000){
			int ans=0;
			for(ll i=1;i<=n;++i)
				for(ll j=1;j<i;++j){
					fBBF[i][j]=0;
					if(j+1==i){
						for(ll k=1;k<j;++k){ 
							if(fBBF[j][k]+(a[k]==a[i])*a[i]>fBBF[i][j]) pre[i]=k;
							fBBF[i][j]=max((ll)fBBF[i][j],(ll)fBBF[j][k]+(a[k]==a[i])*a[i]);
						}
					}else fBBF[i][j]=fBBF[i-1][j]+(a[i-1]==a[i])*a[i];
				}
			for(ll j=1;j<n;++j) ans=max(ans,fBBF[n][j]);
			cout<<ans<<"\n";
		}else if(ma<=13){
			for(ll i=1;i<=n;++i){
				fBF[i]=fBF[i-1]+(a[i-1]==a[i])*a[i]; 
				if(a[i]==a[i-1]) continue;
				ll val=0;
				for(ll j=i-1;j>=1;--j){//枚举蓝色的位置[j,i-1]
					val+=(a[j]==a[j+1])*a[j];
					fBF[i]=max(fBF[i],fBF[j]+(a[j-1]==a[i])*a[i]+val);
					if(a[i]==a[j-1]) break;
				}
			}
			cout<<fBF[n]<<"\n";
		}else{
			buildST(1,1,n);
			for(ll i=1;i<=n;++i){
				f[i]=max((lst[i]?query(1,lst[i]+1,lst[i]+1)+a[i]:0ll),query(1,1,i-1));
				if(a[i]==a[i-1]) f[i]=max(f[i],f[i-1]+a[i]);
				add(1,i,i,f[i]);
				if(a[i]==a[i-1]) add(1,1,i-1,a[i]);
			}
			cout<<f[n]<<"\n";
		}
	}
	return 0;
}
