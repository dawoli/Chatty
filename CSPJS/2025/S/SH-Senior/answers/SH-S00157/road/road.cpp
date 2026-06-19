#include<bits/stdc++.h>
using namespace std;
struct asd{
	long long u,v,w;
}e[2000010];
long long f[10110];
long long find(long long x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(long long x,long long y){
	long long a=find(x),b=find(y);
	if(a!=b)f[a]=b;
}
bool cmp(asd a,asd b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,k,c,ans=0;
	cin>>n>>m>>k;
	c=m;
	for(long long i=1;i<=n+k+1;i++)f[i]=i;
	for(long long i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(long long i=1;i<=k;i++){
		long long t;
		cin>>t;
		for(long long j=1;j<=n;j++)e[++c].u=n+i,e[c].v=j,cin>>e[c].w;
	}
	sort(e+1,e+c+1,cmp);
	for(long long i=1;i<=c;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
} 
