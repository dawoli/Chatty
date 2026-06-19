#include<bits/stdc++.h>
#define ll long long
#define a first
#define b second
using namespace std;
ll u[1000010],v[1000010],w[1000010];
ll c[15][10010];
ll fa[10010];
ll f(int x){
	if(fa[x]!=x)fa[x]=f(fa[x]);
	return fa[x];
}
void read(ll *x){
	*x=0;
	bool flag=0;
	while(1){
		char a=getchar();
		
		if(a>='0' && a<='9'){
			*x = (*x) *10 +a-'0';
			flag=1;
		}
		else if(flag) return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	read(&n);
	read(&m);
	read(&k); 
	for(ll i=1;i<=m;i++){
		read(&u[i]);
		read(&v[i]);
		read(&w[i]); 
	}
	for(ll i=1;i<=k;i++){
		for(ll j=0;j<=n;j++){
			read(&c[i][j]);
		}
	}
	ll minans=1e17;//总答案 
	
	bool flag=0;
	for(int i=1;i<=k;i++)if(c[i][0]!=0)flag=1;
	if(flag){
		for(ll kbit=0;kbit<(ll)1<<k;kbit++){
			for(ll i=1;i<=n+k;i++)fa[i]=i;
			ll ans=0;//这种情况答案多少 
			priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > >pq;
			for(ll i=1;i<=m;i++){
				pq.push({w[i],{u[i],v[i]}});
			}
			ll cntbit=0;//多少村庄 
			for(int i=1;i<=k;i++){
				if((kbit>>(i-1))&1){
					ans+=c[i][0];
					cntbit++;
					for(int j=1;j<=n;j++){
						pq.push({c[i][j],{i+n,j}});
					}
				}
			}
			ll cnt=0;//连了多少边
			while(!pq.empty()){
				pair<ll,pair<ll,ll> >tmp=pq.top();
				pq.pop();
				if(f(tmp.b.a)!=f(tmp.b.b)){
					ans+=tmp.a;
					cnt++;
					fa[f(tmp.b.b)]=f(tmp.b.a);
				}
				if(cnt==n+cntbit-1)break;
			}
			minans=min(minans,ans);
		}
	}
	else{
		ll kbit=(1<<k)-1;
		for(ll i=1;i<=n+k;i++)fa[i]=i;
		ll ans=0;//这种情况答案多少 
		priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > >pq;
		for(ll i=1;i<=m;i++){
			pq.push({w[i],{u[i],v[i]}});
		}
		ll cntbit=0;//多少村庄 
		for(int i=1;i<=k;i++){
			if((kbit>>(i-1))&1){
				ans+=c[i][0];
				cntbit++;
				for(int j=1;j<=n;j++){
					pq.push({c[i][j],{i+n,j}});
				}
			}
		}
		ll cnt=0;//连了多少边
		while(!pq.empty()){
			pair<ll,pair<ll,ll> >tmp=pq.top();
			pq.pop();
			if(f(tmp.b.a)!=f(tmp.b.b)){
				ans+=tmp.a;
				cnt++;
				fa[f(tmp.b.b)]=f(tmp.b.a);
			}
			if(cnt==n+cntbit-1)break;
		}
		minans=min(minans,ans);
	}
		
		
	cout << minans;
	return 0;
}

