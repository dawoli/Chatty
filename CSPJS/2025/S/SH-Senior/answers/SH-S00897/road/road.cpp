#include<bits/stdc++.h>
using namespace std;
long long N,M,K,ds[10055][10055],u,v,m,n[10055],fa[10055],nd[10055][10055],sm,Ans=2147483647;
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
void Union(int x,int y){int X=find(x),Y=find(y);fa[X]=fa[Y];}
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	memset(ds,-1,sizeof(ds));
	cin>>N>>M>>K;
	for(int i=1;i<=M;i++){
		cin>>u>>v>>m;
		ds[u][v]=ds[v][u]=m;
	}
	for(int i=1;i<=K;i++){
		cin>>n[i];
		for(int j=1;j<=N;j++){
			cin>>m;v=j;
			ds[M+i][v]=ds[v][M+i]=m;
		}
	}
	for(int st=1;st<(1<<K);st++){
		memset(nd,0x3f,sizeof(nd));
		for(int i=1;i<=N+K;i++){
			for(int j=1;j<=N+K;j++)nd[i][j]=(ds[i][j]!=-1?ds[i][j]:nd[i][j]);
		}
		for(int i=1;i<=N;i++)fa[i]=i;
		for(int k=1;k<=N+K;k++){
			if(k>N&&(!st&(1<<(k-N-1))))continue;
			for(int i=1;i<=N+K;i++){
				if(i>N&&(!st&(1<<(i-N-1))))continue;
				for(int j=1;j<=N+K;j++){
					if(j>N&&(!st&(1<<(j-N-1))))continue;
					if(i==j||k==i||k==j)continue;
					nd[i][j]=min(nd[i][j],nd[i][k]+nd[k][j]);
				}
			}
		}
		sm=0;
		for(int i=0;i<K;i++)if(st&(1<<i))sm+=n[i];
		for(int i=1;i<=N+K;i++){
			if(i>N&&(!st&(1<<(i-N-1))))continue;
			for(int j=1;j<=N+K;j++){
				if(j>N&&(!st&(1<<(j-N-1))))continue;
				if(nd[i][j]!=0x3f3f3f3f&&find(i)!=find(j)){
					Union(i,j);sm+=nd[i][j];
				}
			}
		}Ans=min(Ans,sm);
	}
	cout<<Ans<<endl;return 0;
}								
