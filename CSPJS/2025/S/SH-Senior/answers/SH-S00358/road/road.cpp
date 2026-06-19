#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+29,M=1e6+9;
int n,m,k;
pair<int,pair<int,int> > edge[M];//<w,<u,v> >
int d[N];
int fd(int x){
	if(d[x]==x)
		return x;
	return d[x]=fd(d[x]);
}
pair<pair<int,pair<int,int> >,int> e[M];//<<w,<u,v> >,els>
int cnt;
int c[20];
void ad0(int u,int v,int w,int xz){
	cnt++,e[cnt].first.first=w,e[cnt].first.second.first=u,e[cnt].first.second.second=v;
	e[cnt].second=xz;
}
int ans=-1;
void dx(int z0){
	bool n01[20]={0};
	int ret=0,num1=0;
	n01[0]=true;
	for(int i=1;i<=k;i++){
		n01[i]=z0&(1<<(i-1));
		if(n01[i])
			ret+=c[i],num1++;
	}
	for(int i=1;i<=n+k;i++)
		d[i]=i;
//	cout<<cnt<<endl;
	int cnt1=0; 
	for(int i=1;i<=cnt&&cnt1<(n+num1-1);i++){
		if(!n01[e[i].second]){
			continue;
		}
		int u=e[i].first.second.first,v=e[i].first.second.second,w=e[i].first.first;
		u=fd(u),v=fd(v);
		if(u!=v){
			d[u]=v;
			ret+=w;
			cnt1++;
//			cout<<w;
		}
	}
//	cout<<':'<<ret<<endl;
	if(ans==-1)
		ans=ret;
	else
		ans=min(ans,ret);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=n;i++)
		d[i]=i;
	for(int i=1;i<=m;i++){
		int w=edge[i].first,u=edge[i].second.first,v=edge[i].second.second;
		u=fd(u),v=fd(v);
		if(u!=v){
			d[u]=v;
			ad0(u,v,w,0);
//			cout<<1;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			ad0(n+i,j,x,i);
		}
	}
	sort(e+1,e+1+cnt);
	for(int z=0;z<(1<<k);z++){
		dx(z);
	}
	cout<<ans;
	return 0;
}
