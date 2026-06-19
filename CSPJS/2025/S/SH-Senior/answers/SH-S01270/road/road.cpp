#include<bits/stdc++.h>
using namespace std;
const int M=1100006,N=10004;
const int K=12;
long long n,m,k,a[K][N],cnt,fa[N],ans,c[N];
struct side{
	int u,v;
	long long w;
};
side s[N];
bool cmp(side x,side y){
	return x.w<y.w; //边权小的放前面 
}
long long find(long long x){
	if(fa[x]==x)
		return x;
	return find(fa[x]);
}
void add(long long x,long long y){
	fa[find(x)]=find(y);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		long long u1,v1,w1;
		cin>>u1>>v1>>w1;
		s[i].u=u1,s[i].v=v1,s[i].w=w1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i]; //将第i个乡镇城市化改造的费用
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		} 
	}
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++){
		long long u1=s[i].u,v1=s[i].v,ww=s[i].w;
		if(find(u1)==find(v1))
			continue;
		add(u1,v1);
		ans+=ww;
	}
	cout<<ans;
	return 0;
} 
