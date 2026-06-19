#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node{
	int u,v,w,id;
}a[M],e[11*N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int cnt=0;
int n,m,k;

int f[N+20];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

int c[20],sz=0,cnts=0;
bool vis[20];
long long ans=0,tmp=0;
inline void calc(int t){
	//cout<<"t = "<<t<<'\n';
	sz=0;cnts=0;tmp=0;
	for(int i=0;i<k;i++){
		if((t>>i)&1){
			vis[i]=1;
			tmp+=c[i];
			sz++;
		}
		else vis[i]=0;
	}
	for(int i=1;i<=n+1+k;i++) f[i]=i;
	int u=0,v=0;
	for(int i=1;i<=cnt;i++){
		if(cnts==n+sz-1){
			break;
		}
		if(e[i].id==-1||vis[e[i].id]){
			u=find(e[i].u);v=find(e[i].v);
			if(u==v) continue;
			
			f[u]=v;
			tmp+=e[i].w;
			cnts++;
			//cout<<e[i].u<<" "<<e[i].v<<" "<<tmp<<'\n';
		}
	}
	ans=min(ans,tmp);
	return;
}
inline bool check(){
	for(int i=0;i<k;i++) if(c[i]) return 0;
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].id=-1;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	int u=0,v=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		u=find(a[i].u);v=find(a[i].v);
		if(u==v) continue;
		f[u]=v;
		e[++cnt]=a[i];
		ans+=a[i].w;
	}
	int d=0;
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>d;
			e[++cnt]={n+1+i,j,d,i};
		}
	}
	sort(e+1,e+1+cnt,cmp);
	//for(int i=1;i<=cnt;i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<e[i].id<<'\n';
	//return 0;
	if(check()){
		calc((1<<k)-1);
	}
	else{
		for(int i=0;i<(1<<k);i++){
			calc(i);
		}	
	}
	
	cout<<ans<<'\n';
	return 0;
}
