#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,flag,fa[1010];
long long tmp[1010][1010]; 
long long ret,u,v,w,c[20],a[20][1010];
struct node2{
	long long uv,vu,z;
};
vector<node2>g;
long long find(long long x){
	if(fa[x]==x){
		return x;
	}return x=find(fa[x]);
}void merge(long long x,long long y){
	fa[find(x)]=find(y);
}int cmp(node2 a,node2 b){
	return a.z<b.z;
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		g.push_back((node2){u,v,w});
		g.push_back((node2){v,u,w});
	}for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				tmp[i][j]=0x3f3f3f3f3f3f3f3fll;
				for(int l=1;l<=k;l++){
					tmp[i][j]=min(tmp[i][j],c[l]+a[l][i]+a[l][j]);
				}
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				g.push_back((node2){i,j,tmp[i][j]});
			}
		}
	}sort(g.begin(),g.end(),cmp);
	for(int i=1;i<=(int)g.size();i++){
		if(cnt==n-1){
			printf("%lld",ret);
			return 0;
		}if(find(g[i].uv)!=find(g[i].vu)){
			merge(g[i].uv,g[i].vu);
			ret+=g[i].z;
			cnt++;
		}
	}return 0;
}
