#include<bits/stdc++.h>
using namespace std;
long long sum;
struct stu{
	int u,v,w;	
}g[1050010];
bool cmp(stu a,stu b){
	if(a.w==b.w){
		return a.u<b.u;
	}
	return a.w<b.w;
}
int n,m,k;
int c[1000005],a[10005][11],lian[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
		}
	}
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=m;i++){
		int ff=1;
		for(int j=1;j<=k;j++){
			if(c[j]+a[g[i].u][j]+a[g[i].v][j]<g[i].w){
				sum+=c[j]+a[g[i].u][j]+a[g[i].v][j];


				ff=0;
			}
		}
		if(ff==0){
			continue;
		}
		if(lian[g[i].u]==0||lian[g[i].v]==0){
			sum+=g[i].w;
		}
		if(lian[g[i].u]==0){
			
			lian[g[i].u]=1;
		}
		if(lian[g[i].v]==0){
			lian[g[i].v]=1;
		}
		

	}
	int f=1;
	for(int i=1;i<=n;i++){
		if(lian[i]==0){
			int minn=2147483647;
			for(int j=1;j<=k;j++){
				minn=min(minn,c[j]+a[i][j]+a[i][j]);
			}
			if(minn==2147483647){
				continue;
			}
			sum+=minn;

		}
	}
	cout<<sum;
	return 0;
}
