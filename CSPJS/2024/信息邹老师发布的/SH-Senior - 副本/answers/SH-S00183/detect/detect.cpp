#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,LL=1000005;
bool q[LL];
struct qujian{
	ll l,r;
}a[N];
bool cmp(qujian x,qujian y){
	if(x.r==y.r)
		return x.l>y.l;
	return x.r<y.r;
}
ll c2[LL];
ll lowbit(ll x){
	return x&(-x);
}
ll query2(ll p){
	ll ans=0;
	while(p>0){
		ans+=c2[p];
		p-=lowbit(p);
	}
	return ans;
}
void updata2(ll p,ll x){
	while(p<=LL){
		c2[p]+=x;
		p+=lowbit(p);
	}
}
void clear(){
	memset(c2,0,sizeof(c2));
	memset(q,0,sizeof(q));
}
void solve(){
	ll n,m,L,V;
	cin>>n>>m>>L>>V;
	L++;
	ll cnt=0;
	//wei hu qu jian 
	for(int i=1;i<=n;i++){ 
		ll d,v,aa;
		cin>>d>>v>>aa;
		d++;
		if(aa==0){
			if(v<=V)continue;
			else{
				a[++cnt].l=d,a[cnt].r=L;
			}
		}
		if(aa>0){
			if(v>V){
				a[++cnt].l=d,a[cnt].r=L;
			}
			else{
				double t=1.0*(V*V-v*v)/(2*aa);
				if(t==ceil(t))t=ceil(t)-1;
				else t=ceil(t);
				if(d+t>L)continue;
				else{a[++cnt].l=d+t,a[cnt].r=L;}
			}
		}
		if(aa<0){
			if(v<=V)continue;
			else{
				a[++cnt].l=d;
				aa=-aa;
				ll t=(v*v-V*V-0.1)/(2*aa);
				a[cnt].r=min(d+t,L);
			}
			
		}
	}	
//	for(int i=1;i<=cnt;i++)cout<<a[i].l<<" "<<a[i].r<<endl;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		x++;
		q[x]=1;
	}
	ll ans1=0,ans2=0;
	for(int i=1;i<=cnt;i++){
		ll pp=a[i].r;
		ll mst=query2(a[i].r)-query2(a[i].l-1);
		if(mst>0)ans1++;
		if(mst==0){
			for(pp;pp>=a[i].l;pp--){
				if(q[pp]==1){
				updata2(pp,1);
				ans2++;
				ans1++;
				break;
				}
			}
		}
	}

	cout<<ans1<<" "<<m-ans2<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		clear();
		solve();
	}
	return 0;
}
