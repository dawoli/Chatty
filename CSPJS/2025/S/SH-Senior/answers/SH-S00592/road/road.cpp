#include<bits/stdc++.h>
using namespace std;
//dsu
#define ll long long
ll fa[int(1e7)]={0};
ll n,m,k;
ll a[10][int(1e5)];
ll size[int(1.5e4)];
ll find(int x){
	//cerr<<"Finding "<<x<<"fa="<<fa[x];
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unite(ll x,ll y){
	int fy=find(y),fx=find(x);
	fa[fy]=fx;
}

struct edge{
	ll x,y,w,belong;
	bool isbase;
} e[int(1e7)];
bool cmpw(edge a,edge b){
	return a.w<b.w;
}
ll kruskal(ll bitmask){
	for(int i=1;i<=n+k+5;i++){
		fa[i]=i;
		size[i]=1;
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(not e[i].isbase){
			if(((1ll<<(e[i].belong/2))&bitmask)==0){
				//clog<<"Jumping Edge"<<e[i].x<<" "<<e[i].y<<"\n";
				continue;
				
			}
			
		}
		//cerr<<"Trying"<<i<<find(e[i].x)<<" "<<find(e[i].y)<<endl;
		if(find(e[i].x)!=find(e[i].y)){
			//cerr<<"Unite"<<e[i].x<<" "<<e[i].y<<" "<<e[i].w<<endl;
			ans+=e[i].w;
			unite(e[i].x,e[i].y);
			//clog<<"Ok"<<e[i].x<<" "<<e[i].y<<endl;
		}
	}
	return ans;
}
//void dsutest(){
//	for(int i=1;i<=1000;i++){
//		fa[i]=i;
//		size[i]=1;
//	}
//	while(true){
//		string op;
//		cout<<"OP:";
//		cin>>op;
//		if(op=="u"){
//			int x,y;
//			cin>>x>>y;
//			unite(x,y);
//		}else{
//			int x;
//			cin>>x;
//			cout<<find(x)<<"\n"; 
//		}
//	}
//}
ll qpt[15];
int main(){
	//dsutest();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[i].x=x;
		e[i].y=y;
		e[i].w=z;
		e[i].isbase=true; 
		e[i].belong=0;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			++m;
			e[m].x=m+10+i;
			e[m].y=j;
			e[m].w=a[i][j];
			e[m].isbase=false; 
			e[m].belong=i;
		}
		
	}
//	for(int i=1;i<=15;i++){
//		printf("Edge#%d from %d to %d weight %d\n",i,e[i].x,e[i].y,e[i].w);
//	}
	sort(e+1,e+m+1,cmpw);
	qpt[0]=1;
	qpt[1]=2;
	for(int i=2;i<=12;i++){
		qpt[i]=qpt[i-1]*2;
	}
	ll im=m,ans=INT_MAX;

	for(ll ib=0;ib<qpt[k];ib++){
		int i=ib,c=1,tc=0;
		//printf("IB=%lld\n",ib);
		for(int j=1;j<=k;j++){
			if(((1ll<<(j/2))&ib)!=0){
				tc+=a[j][0];
			}
		}
		ll kr=kruskal(ib);
		ans=min(kr+tc,ans);
		m=im;
	}
	cout<<ans;
}
