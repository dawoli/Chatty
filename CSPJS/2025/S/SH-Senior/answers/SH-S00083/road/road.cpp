#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1000009;
const int N=10009;
struct edge{
	ll u,v,w;
	bool operator <(const edge&other) const{
		return w<other.w;
	}
} e[2*M];
ll d[N+100];
ll find(int u){
	return u==d[u]?u:(d[u]=find(d[u]));
}
ll n,m,k,ans,cnt,c[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll u,v,w;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[i]=(edge){u,v,w};
	}
	cnt=0;
	for(ll i=1;i<=n;i++) d[i]=i;
	sort(e+1,e+1+n);
	for(ll i=1;i<=m,cnt<n;i++){
		ll u=e[i].u,v=e[i].v;
		if(find(u)==find(v)) continue;
		d[v]=u;
		cnt++;
		ans+=e[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			ll a;
			cin>>a;
			e[m+(i-1)*n+j]=(edge){j,n+i,a};
		}
	}
	sort(e+1,e+1+m+k*n);
	ll ls_ans;
	for(ll num=1;num<=pow(2,k)-1;num++){
		ls_ans=0;
		cnt=0;
		ll count=0;
		for(ll i=0;i<=k-1;i++){
			if(((ll)pow(2,i)&num)!=0){
				ls_ans+=c[i+1];
				count++;
			}
		}
		for(ll i=1;i<=n+k;i++) d[i]=i;
		for(ll i=1;i<=m+k*n&&cnt<n+count-1;i++){
			ll u=e[i].u,v=e[i].v;
			if((v>n)&&(((ll)pow(2,(v-n-1))&num)==0)) continue;
			if(find(u)==find(v)) continue;
			d[v]=u;
			cnt++;
			ls_ans+=e[i].w;
		}
		ans=min(ls_ans,ans);
	}
	cout<<ans<<endl;
	return 0;
} 
