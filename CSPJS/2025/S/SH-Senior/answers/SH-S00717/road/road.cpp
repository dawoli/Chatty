#include<bits/stdc++.h>
using namespace std;
const int N=1e4+29;
const int M=1e6+9;
struct Edge{
	int u,v;
	long long w;
	bool operator<(const Edge X){
		return w<X.w;
	}
}e[M],g[20][N];
int T[20];
bool vis[N];
int n,m,k,l;
long long sum,ans;
long long c[20],a[20][N];
int p[20];
int f[N];
int find(int x){
	return f[x]?f[x]=find(f[x]):x; 
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return false;
	f[x]=y;
	return true;
}
bool C(Edge E){
	return find(E.v)==find(E.u);
}
void SV(){
	memset(f,0,sizeof f);
	for(int i=0;i<=l;i++)
		p[i]=1;
	for(int cnt=1;cnt<n+l;cnt++){
		Edge mn;
		if(p[0]>n)mn=(Edge){0,0,1e18+9};
		else {
			while(C(e[p[0]]))p[0]++;
			if(p[0]>n)mn=(Edge){0,0,1e18+9};
			else mn=e[p[0]];
		}
		for(int i=1;i<=l;i++){
			if(p[i]>n)continue;
			int nw=T[i];
			while(C(g[nw-n][p[i]]))p[i]++;
			if(p[i]>n)continue;
			if(g[nw-n][p[i]]<mn)
				mn=g[nw-n][p[i]];
		}
		merge(mn.u,mn.v);
		sum+=mn.w;
	}
}
long long Read(){
	char c;
	c=getchar();
	while(!('0'<=c&&c<='9'))c=getchar();
	long long sum=0ll;
	while('0'<=c&&c<='9')
		sum=sum*10ll+c-'0',c=getchar();
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=Read(),m=Read(),k=Read();
	for(int i=1;i<=m;i++){
		long long u,v,w;
		u=Read(),v=Read(),w=Read();
		e[i]=(Edge){u,v,w};
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v))
			e[++l]=e[i];
	}
	m=l;
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++){
			scanf("%d",a[i]+j);
			g[i][j]=(Edge){i+n,j,a[i][j]};
		}
		sort(g[i]+1,g[i]+1+n);
	}
	ans=1e18+9;
	for(int s=0;s<(1<<k);s++){
		sum=0,l=0;
		for(int j=1;j<=k;j++){
			if(s&(1<<j-1))
				sum+=c[j],T[++l]=n+j;
		}
		SV();
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
