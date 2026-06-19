#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
ll n,m,k,u,v,w,ans;
vector<int> W[N],to[N];
struct abc{
	int c,a[N];
	int so;
} ex[11];
bool cmp(abc x,abc y){
	return x.so<y.so;
}
int vis[N],evis[N];
#define pii pair<int,int>
void cul(){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=0;i<to[1].size();i++)
		q.push({W[1][i],to[1][i]});
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(vis[u.second]!=0) continue;
		vis[u.second]=u.first;
		for(int i=0;i<to[u.second].size();i++){
			int v=to[u.second][i];
			if(vis[v]==0){
				q.push({W[u.second][i],v});
			}
		}
	}
}
void excul(abc e){
	int mi=e.a[1];
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=0;i<to[1].size();i++)
		q.push({W[1][i],to[1][i]});
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(evis[u.second]!=0) continue;
		evis[u.second]=u.first;
		if(mi+e.a[u.second]<=evis[u.second])
			evis[u.second]=mi+e.a[u.second],mi=0;
		else
			mi=min(mi,e.a[u.second]);
		for(int i=0;i<to[u.second].size();i++){
			int v=to[u.second][i];
			if(evis[v]==0){
				q.push({min(W[u.second][i],mi+e.a[v]),v});
			}
		}
	}
}
void check(){
	for(int i=2;i<=n;i++)
		ans+=vis[i];
	for(int i=1;i<=k;i++){
		ll sum=ex[i].c;
		excul(ex[i]);
		for(int i=2;i<=n;i++)
			sum+=evis[i];
		if(sum<ans){
			for(int i=2;i<=n;i++)
				vis[i]=evis[i];
			ans=sum;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		to[u].push_back(v);
		to[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	cul();
	for(int i=1;i<=k;i++){
		int ma=1e9,sma=1e9,f=0;
		cin>>ex[i].c;
		for(int j=1;j<=n;j++){
			cin>>ex[i].a[j];
			f+=ex[i].a[j];
			if(ex[i].a[j]<ma)
				sma=ma,ma=ex[i].a[j];
			else if(ex[i].a[j]<sma)
				sma=ex[i].a[j];
		}
		ex[i].so=ma+sma+ex[i].c;
		if(f==0){
			cout<<ex[i].c;
			return 0;
		}
	}
	sort(ex+1,ex+1+k,cmp);
	check();
	cout<<ans;
	return 0;
} 
