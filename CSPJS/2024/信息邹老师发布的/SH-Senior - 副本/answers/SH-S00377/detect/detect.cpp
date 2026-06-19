#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N=1e5+9;
ll T,n,m,L,V;
struct Car{
	ll d,v,a;
}c[N];
struct Range{
	ll l,r;
	bool operator<(const Range&x)const{
		return r==x.r?l<x.l:r<x.r;
	}
}rg[N];
struct Rank{
	ll rk;
	bool operator<(const Rank&x)const{
		return rg[rk].l==rg[x.rk].l?rk>x.rk:rg[rk].l<rg[x.rk].l;
	}
}rk[N];
ll nR;
ll p[N];
bool shut[N],isExd[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		nR=0;
		for(int i=1;i<=n;i++)
			isExd[i]=0;
		for(int i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++)
			cin>>p[i];
		p[m+1]=-1e9;
		sort(p+1,p+m+1); 
		//ans1:
		ll ans1=0;
		for(int i=1;i<=n;i++){
			ll s,v0=c[i].v,a=c[i].a;
			if(a>=0)
				s=p[m]-c[i].d;
			else
				s=*lower_bound(p+1,p+m+1,c[i].d)-c[i].d;
//			cout<<"DEBUG: "<<i<<" "<<s<<endl; 
			if(s<0)
				continue;
//			cout<<"DEBUG: "<<i<<endl; 
			ll sq_inst=v0*v0+2*a*s;
//			cout<<"DEBUG: "<<sq_inst<<" "<<V*V<<endl;
			if(sq_inst>V*V)
				ans1++,isExd[i]=1;
		}
		cout<<ans1<<" ";
		//ans2:
		for(int i=1;i<=n;i++){
			if(!isExd[i]) continue;
			ll v0=c[i].v,a=c[i].a,d=c[i].d;
			if(a==0)
				rg[++nR]=(Range){lower_bound(p+1,p+m+1,d)-p,m};
			else if(a>0){
				ll l=1,r=m,ans=-1;
				while(l<=r){
					ll mid=(l+r)/2;
					if(p[mid]*2*a>(V-v0)*(v0+V)+2*a*d){
						r=mid-1;
						ans=mid;
					}
					else
						l=mid+1; 
				}
				rg[++nR]=(Range){ans,m};
			}
			else{
				ll l=1,r=m,ans=-1;
				while(l<=r){
					ll mid=(l+r)/2;
					if(p[mid]*2*a>(V-v0)*(v0+V)+2*a*d){
						l=mid+1;
						ans=mid;
					}
					else
						r=mid-1; 
				}
				rg[++nR]=(Range){lower_bound(p+1,p+m+1,d)-p,ans};
			}
		}
		sort(rg+1,rg+nR+1);
		for(int i=1;i<=nR;i++)
			rk[i]=(Rank){i};
		sort(rk+1,rk+nR+1);
		ll lb=1;
		ll ans2=m;
		for(int i=1;i<=nR;i++)
			shut[i]=0;
		for(int i=1;i<=nR;i++){
			if(shut[i]) continue;
//			cout<<"DEBUG: "<<i<<endl;
			ans2--;
			ll j;
			for(j=lb;j<=nR;j++){
				if(rg[rk[j].rk].l>rg[i].r) break;
				shut[rk[j].rk]=1;
			}
			lb=j;
		}
		cout<<ans2<<endl;
	}
	return 0;
}
