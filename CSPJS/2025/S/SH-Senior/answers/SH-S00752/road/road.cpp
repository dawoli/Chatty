#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u,v;
long long ans=0;
long long c[1000000];
long long a[1000000];
long long Num[10010][10010];
bool Vis[1000000];
struct Node{
    long long x,t,w,f;
    bool operator <(const Node &A)const{
    	return w+(!Vis[f])*c[f]>A.w+(!Vis[A.f])*c[A.f];
	}
}e;
priority_queue<Node>Q;
long long P[1000000];
long long Find(long long X){
	if(P[X]==X) return X;
	P[X]=Find(P[X]);
	return P[X];
}
void Union(long long i,long long j){P[Find(i)]=Find(j);}
void Krusk(){
	while(!Q.empty()){
		e=Q.top();Q.pop();
		if(Find(e.x)==Find(e.t)) continue;
		ans+=e.w+(!Vis[e.f])*c[e.f];
		Vis[e.f]=true;
		Union(e.x,e.t);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) P[i]=i;
	memset(Vis,false,sizeof(Vis));
	Vis[0]=true;
	memset(Num,0x3f3f3f3f,sizeof(Num));
	for(long long i=1;i<=m;i++){
		cin>>u>>v>>e.w;
		if(e.w>=Num[u][v]) continue;
		e.t=u;e.f=0;e.x=v;
		Q.push(e);
		Num[u][v]=Num[v][u]=e.w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++) cin>>a[j];
		for(long long j=1;j<=n;j++){
			for(long long p=j+1;p<=n;p++){
				e.w=a[j]+a[p],e.f=i;
				if(e.w>=Num[j][p]) continue;
				Num[j][p]=Num[p][j]=e.w;
				e.t=k;e.x=j;
				Q.push(e);
			}
		}
	}
	Krusk();
	printf("%lld\n",ans);
	return 0;
}
