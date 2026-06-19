#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
const ll INF=1e9;
const double INFF=1e-9;
ll p[N],d[N],v[N],a[N];
ll lp[N],rp[N];
double stp[N],faster[N];
bool ok[N];
ll T,n,m,L,V;
vector<ll> cnt[N];
ll sum[N];
struct vec{
	ll si;
	ll id;
} pai[N];

bool cmp(const vec&a,const vec&b){
	return a.si<b.si;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		
		for(ll i=1;i<=n;++i){
			cin>>d[i]>>v[i]>>a[i];
			
			if(a[i]>0) stp[i]=L*1.0;
			if(a[i]==0){
				if(v[i]<=V) stp[i]=-1;
				else stp[i]=L*1.0;
			}
			if(a[i]<0){
				if(v[i]<=V) stp[i]=-1;
				else {
					double dis=(V*V-v[i]*v[i])*1.0/(2*a[i])*1.0;
					stp[i]=dis+d[i]-INFF;
				}
			}
			if(a[i]>0){
				if(v[i]>V) faster[i]=d[i];
				else{
					double dis=(V*V-v[i]*v[i])*1.0/(2*a[i])*1.0;
					faster[i]=dis+d[i]+INFF;
					if(faster[i]>L) faster[i]=INF;
				}
			}
			if(a[i]==0){
				if(v[i]>V) faster[i]=d[i];
				else faster[i]=INF;
			}
			if(a[i]<0){
				if(v[i]<=V) faster[i]=INF;
				else{
					faster[i]=d[i];
				}
			}
			
		}
		
		for(ll i=1;i<=m;++i){
			cin>>p[i];
		}
		
		ll ans=0;
		
		for(ll i=1;i<=n;++i){
			ll l=1,r=m;
			lp[i]=-1;rp[i]=-1;
			
			while(l<=r){
				ll mid=(l+r)/2;
				if(p[mid]>=faster[i]){
					r=mid-1;
					lp[i]=mid;
				}
				else{
					l=mid+1;
				}
			}
			
			l=1;
			r=m;
			while(l<=r){
				ll mid=(l+r)/2;
				if(p[mid]<=stp[i]){
					l=mid+1;
					rp[i]=mid;
				}
				else{
					r=mid-1;
				}
			}
			
			if(rp[i]!=-1&&lp[i]!=-1&&lp[i]<=rp[i]){
				ok[i]=1;
				ans++;
				
				for(ll k=lp[i];k<=rp[i];++k){
					cnt[k].push_back(i);
					sum[i]++;
				}
			}
			
		}
		
		cout<<ans<<' ';
		
		for(ll i=1;i<=m;++i){
			pai[i].si=cnt[i].size();
			pai[i].id=i;
		}
		
		sort(pai+1,pai+1+m,cmp);
		
		ll ans2=0;
		
		for(ll i=1;i<=m;++i){
			
			ll leng=cnt[pai[i].id].size();
			bool kll=0;
			
			for(ll j=0;j<leng;++j){
				if(sum[cnt[pai[i].id][j]]<=1) kll=1; 
			} 
			
			if(kll==0){
				ans2++;
				for(ll j=0;j<leng;++j){
					sum[cnt[pai[i].id][j]]-=1; 
				} 
			}
		}
		
		cout<<ans2<<endl;
	}
	return 0;
}
