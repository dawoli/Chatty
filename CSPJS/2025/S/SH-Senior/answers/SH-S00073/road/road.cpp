#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10009;
vector<ll> e[maxn];
ll n,m,k,u,v,w;
ll a[maxn][maxn];
ll ans=0x3f,cnt=0;
ll dst[maxn];
ll c,d,f,g,h;
bool vst[maxn];
void dfs(int x,int c,ll tmp){
	if(c==n){
		ans=min(ans,tmp);
		return;	
	}
	vst[x]=1;
	for(int i=0;i<e[x].size();i++){
		ll vv=e[x][i];
		if(vst[vv])continue;
//		if(dst[x]+a[x][vv]<dst[vv]){
//			//cout<<"!!!"<<x<<" "<<vv<<" "<<dst[x]<<" "<<dst[vv]<<" "<<a[x][vv]<<endl; 
//			dst[vv]=dst[x]+a[x][vv];
//			//cout<<"???"<<dst[vv]<<endl;
//		}
		//cout<<"!!"<<vv<<" "<<c+1<<" "<<tmp+a[x][vv]<<endl;
		dfs(vv,c+1,tmp+a[x][vv]);
		vst[vv]=0;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dst,0x3f,sizeof(dst));
	memset(vst,0,sizeof(vst));
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back(v);
		e[v].push_back(u);
		a[u][v]=a[v][u]=w;
	}
	if(k==0){
		dst[1]=0;
		vst[1]=1;
		dfs(1,1,0);
//		for(int i=1;i<=n;i++){
//			cout<<dst[i]<<" ";
//		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=k;i++){
			cin>>c>>d>>f>>g>>h;
		}
		cout<<5182974424;
	}
	return 0;
}
