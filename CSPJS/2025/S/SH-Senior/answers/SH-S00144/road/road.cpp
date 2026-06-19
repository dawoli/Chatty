#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1919810,M=114514;
struct node{
	int x,y,z;
}e[N];
int fa[M],a[10][M],v[1325][1325],n,m,k,c,t;
bool cmp(node x,node y){
	return x.z<y.z;
}
int fnd(int x){
	if(fa[x]!=x)fa[x]=fnd(fa[x]);
	return fa[x];
}
int kruskal(){
	int s=0;
	sort(e+1,e+c+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=c;i++){
		int u=e[i].x,v=e[i].y,w=e[i].z;
		if(fnd(u)==fnd(v))continue;
		fa[fnd(u)]=fnd(v);
		s+=w;
	}return s;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(v,0x3f,sizeof(v));
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		v[x][y]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				v[j][k]=min(v[j][k],a[i][j]+a[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			v[i][j]=min(v[i][j],v[j][i]);
			if(v[i][j]!=0x3f3f3f3f3f3f3f3f)
			e[++c].x=i,e[c].y=j,e[c].z=v[i][j];
		}
	}
	for(int i=1;i<=c;i++){
//		cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].z<<endl;
	}
	cout<<kruskal()<<'\n';
}
