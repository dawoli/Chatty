#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,cnt2;
int fa[10005],v[11];
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	fa[find(x)]=find(y);
}
struct node{
	int u,v,w;
	bool operator<(const node &x)const{
	    return w<x.w;
	}
}e[1000005],b[200005],fz[11][200005],a[11][20005],c[20005];
void mg(int k,int cnt){
	//cout<<"."<<" "<<cnt<<endl; 
	for(int i=1,j=1;i<=cnt||j<=n;){
		if(j>n||i<=cnt&&b[i]<a[k][j]){
			c[i+j-1]=b[i];
			i++;
		} 
		else{
			c[i+j-1]=a[k][j];
			j++;
		}
	}
	for(int i=1;i<=cnt+n;i++){
		b[i]=c[i];
	}
	//cout<<"/"<<endl;
}
int calc(int cnt){
	int sm=cnt*n+n-1,ret=0,cntt=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=sm;i++){
		if(find(b[i].u)!=find(b[i].v)){
			merge(b[i].u,b[i].v);
			ret+=b[i].w;
			//cout<<ret<<" "<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
			cntt++;
		}
		if(cntt==n+cnt-1) break;
	}
	//cout<<ret<<endl;
	return ret;
}
int dfs(int pos,int val,int cnt){
	if(pos==k+1) return calc(cnt)+val;
	int ret=dfs(pos+1,val,cnt);
	for(int i=1;i<=n-1+cnt*n;i++) fz[pos][i]=b[i];
	mg(pos,cnt*n+n-1);
	ret=min(ret,dfs(pos+1,val+v[pos],cnt+1));
	for(int i=1;i<=n-1+cnt*n;i++) b[i]=fz[pos][i];
	return ret;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			b[++cnt2]=e[i];
			merge(e[i].u,e[i].v);
		}
		if(cnt2==n-1) break;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j].w;
			a[i][j].u=i+n,a[i][j].v=j;
		}
		sort(a[i]+1,a[i]+n+1);
	}
	cout<<dfs(1,0,0)<<endl;
}
