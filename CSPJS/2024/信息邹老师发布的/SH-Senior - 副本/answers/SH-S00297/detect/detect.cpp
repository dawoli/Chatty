#include<bits/stdc++.h>
#define ll long long
const int N=1e5+5;
using namespace std;
ll n,m,L,V,p[N],t,f[N];
struct node{
	ll d,v,a;
}c[N];
struct ne{
	ll l,r;
}ans[N];
bool cmp(ne x,ne y){
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		ll cnt=0,num=0,sum=0;
		memset(c,0,sizeof c);
		memset(p,0,sizeof p);
		memset(ans,0,sizeof ans);
		memset(f,0,sizeof f);
		cin>>n>>m>>L>>V;
		for(ll i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(ll i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		for(ll i=1;i<=n;i++){
			if(c[i].d>p[m]) continue;
			if(c[i].a==0){
				ll x=p[m];
				if(c[i].d<=x&&c[i].v>V){
					ll y=lower_bound(p+1,p+m+1,c[i].d)-p;
					ans[++num]={y,m};
					cnt++;
				} 
			}
			else if(c[i].a>0){
				ll x=p[m];
				if(c[i].d<=x&&c[i].v>V){
					ll xy=lower_bound(p+1,p+m+1,c[i].d)-p;
					ans[++num]={xy,m};
					cnt++;
					continue;
				} 
				double ti=(V*V-c[i].v*c[i].v)/(2*c[i].a)+c[i].d;
				if(ti<p[m]){
					cnt++;
					ll tt=floor(ti+1);
					ll o=lower_bound(p+1,p+m+1,tt)-p;
					ans[++num]={o,m};
				} 
			}
			else if(c[i].a<0){
				if(c[i].v<=V) continue;
				ll x=lower_bound(p+1,p+m+1,c[i].d)-p;
				double len=(-c[i].v*c[i].v)/(2*c[i].a);
				if(p[x]-c[i].d>=len) continue;
				double ti=sqrt(c[i].v*c[i].v+(p[x]-c[i].d)*2*c[i].a);
				double vv=V;
				if(ti>V){
					cnt++;
					double le=(V*V-c[i].v*c[i].v)/(2*c[i].a)+c[i].d;
					ll lenl=ceil(le);
					ll y=lower_bound(p+1,p+m+1,lenl)-p-1;
					ans[++num]={x,y};
				} 
			}
		}
		cout<<cnt<<" ";
		sort(ans+1,ans+num+1,cmp);
		for(ll i=1;i<=num;i++){
			f[i]=1;
			if(ans[i].l==ans[i-1].l) f[i]=0;
		}
		ll pre=1;
		for(ll i=2;i<=num;i++){
			if(!f[i]) continue;
			if(ans[i].l>ans[pre].r){
				pre=i;
				continue;
			}
			f[pre]=0;
			ans[i]={ans[i].l,min(ans[i].r,ans[pre].r)};
			pre=i;
		}
		for(ll i=1;i<=num;i++){
			if(f[i]) sum++;
		}
		cout<<m-sum<<endl;
	}
	return 0;
}
