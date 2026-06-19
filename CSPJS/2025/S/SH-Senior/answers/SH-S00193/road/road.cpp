#include<bits/stdc++.h>
#define int long long
using namespace std;


int n,m,k,fa[10000+50],cc[15],a[15][10000+50],totans=10000000,u[10000+50],v[10000+50],c[10000+50];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>cc[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<=(1<<k);i++){
		int choose[15],ans=0;
		for(int j=1;j<=m;j++)fa[j]=j;
		for(int j=10001;j<=10000+k;j++)fa[j]=j;
		int uu=i;
		for(int j=1;j<=k;j++){
			if(uu%2==1)choose[j]=1;
			else choose[j]=0;
			uu>>=1;
		}
		priority_queue<tuple<int,int,int>,vector<tuple<int,int,int> >,greater<tuple<int,int,int> > >Q;
		for(int j=1;j<=m;j++){
			Q.push(make_tuple(c[j],u[j],v[j]));
		}
		for(int j=1;j<=k;j++){
			if(choose[j]==1)continue;
			ans+=cc[j];
			for(int l=1;l<=n;l++)Q.push(make_tuple(a[j][l],j,l));
		}
		while(!Q.empty()){
			auto uu=Q.top();Q.pop();
			int frm=get<1>(uu),v=get<2>(uu);
			if(find(frm)==find(v))continue;
			fa[find(v)]=find(frm);
			ans+=get<0>(uu);
		}
		totans=min(ans,totans);
	}
	cout<<totans<<endl;
}
