#include<bits/stdc++.h>
using namespace std;
typedef int ll;
inline ll read(){
	ll c=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<1)+(c<<3)+(ch^48);
		ch=getchar();
	}
	return c*f;
}
const ll N=200009;
ll n,m;
ll T;
ll t[4];
ll a[N];
ll c[N];
vector<ll> tag[N];
ll K;
struct result{
	ll l,r,res,op,lmt,lr,rr;
} p[2*N];
ll pid[N];
void build(ll u,ll l,ll r){
	p[u]={-1,-1,-1,-1,-1,l,r};
	if(l==r){
		pid[l]=u;
		return;
	}
	ll mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
}
long long ans[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	for(ll i=1;i<=m;i++){
		c[i]=read();
		tag[c[i]].push_back(i);
	}
	K=__lg(n);
	if(n!=(1<<K)) K++;
	build(1,1,(1<<K));
	for(ll i=1;i<=K;i++){
		string s;
		cin>>s;
		for(ll j=0;j<(1<<(K-i));j++){
			ll now=K-i;
			ll id=(1<<now)+j;
			p[id].op=(s[j]=='1');
			p[id].lmt=i;
		}
	}
//	for(ll i=1;i<=(1<<(K+1));i++){
//		cout<<i<<" "<<p[i].l<<" "<<p[i].r<<" "<<p[i].op<<" "<<p[i].lmt<<" "<<p[i].res<<endl;
//	}
//	for(ll i=1;i<=n;i++){
//		cout<<pid[i]<<" ";
//	}
//	cout<<endl;
	T=read();
	while(T--){
		for(ll i=0;i<4;i++){
			t[i]=read();
		}
		for(ll i=1;i<=n;i++){
			a[i]=a[i]^t[i%4];
		}
		for(ll i=1;i<=n;i++){
//			cout<<"i: "<<i<<endl;
			ll id=pid[i];
			bool pos=id&1;
			ll now=i;
			p[id].l=i,p[id].r=i,p[id].res=i;
			while(id!=1){
				id/=2;
				if(pos==0){
					p[id].l=now;
					if(p[id].op==0){
						if(a[now]>=p[id].lmt){
							p[id].res=now;
						}
						else{
							break;
						}
					}
					else{
						break;
					}
					now=p[id].res;
				}
				else{
					p[id].r=now;
					if(p[id].res!=-1){
						break;
					}
					if(a[now]>=p[id].lmt){
						p[id].res=now;
					}
					else{
						p[id].res=p[id].l;
					}
					now=p[id].res;
				}
				pos=id&1;
			}
			
//			for(ll i=1;i<=(1<<(K+1));i++){
//				cout<<i<<" "<<p[i].l<<" "<<p[i].r<<" "<<p[i].op<<" "<<p[i].lmt<<" "<<p[i].res<<endl;
//			}
//			cout<<"-------"<<endl;
			if(tag[i].size()!=0){
				ll k=__lg(i);
				if(i!=(1<<k)) k++;
				ll id2=(1<<(K-k));
				ll ttt=1<<k;
				if(p[id2].res!=-1){
					for(ll u:tag[i]){
						ans[u]=p[id2].res;
					}
					continue;
				}
				else{
					for(ll u:tag[i]){
						ans[u]=1ll*(ttt+i+1)*(ttt-i)/2;
					}
				}
			}
		}
		long long Ans=0;
		for(ll i=1;i<=m;i++){
			Ans^=(1ll*i*ans[i]);
		}
		printf("%lld\n",Ans);
	}
	return 0;
}

