#include<bits/stdc++.h>
#define M 1000005
#define N 10005
using namespace std;
int n,m,k,c[15],a[15][N],root[N];
bool ok[M];
struct edge{
	int u,v,w;
}e[M<<1];
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
int findroot(int u){
	if(u==root[u]) return u;
	return root[u]=findroot(root[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool A=true,B;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]>0) A=false;
		B=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];	
			if(a[i][j]==0) B=true;
		}
		if(!B) A=false;
	}
	for(int i=1;i<=n;i++) root[i]=i;
	if(k==0){
		sort(e+1,e+m+1,cmp);
		int cnt=0,ans=0;
		for(int i=1;i<=m;i++){
			if(findroot(e[i].u)!=findroot(e[i].v)){
				cnt++;
				ans+=e[i].w;
				root[root[e[i].v]]=root[e[i].u];
				if(cnt==n-1) break;
			}
		}
		cout<<ans;
	}
	else if(A){
		for(int i=1,u;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					u=j;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				if(j==u) continue;
				m++;
				e[m]=(edge){u,j,a[i][j]};
			}
		}
		sort(e+1,e+m+1,cmp);
		int cnt=0,ans=0;
		for(int i=1;i<=m;i++){
			if(findroot(e[i].u)!=findroot(e[i].v)){
				cnt++;
				ans+=e[i].w;
				root[root[e[i].v]]=root[e[i].u];
				if(cnt==n-1) break;
			}
		}
		cout<<ans;
	}
	else{
		sort(e+1,e+m+1,cmp);
		int cnt=0,ans=0;
		for(int i=1;i<=m;i++){
			if(findroot(e[i].u)!=findroot(e[i].v)){
				cnt++;
				ans+=e[i].w;
				root[root[e[i].v]]=root[e[i].u];
				ok[i]=true;
				if(cnt==n-1) break;
			}
		}
		cout<<ans;
	}
	return 0;
}

