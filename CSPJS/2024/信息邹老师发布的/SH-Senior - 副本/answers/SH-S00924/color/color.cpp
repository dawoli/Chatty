#include<bits/stdc++.h> 
#define N 200009
using namespace std;
long long ans;
int n,a[N],T;
void dfs(int lstrd,int lstbl,int nnisth,long long qdh){
	if(nnisth>n){
		ans=max(ans,qdh);
		return;
	}
	if(lstrd==a[nnisth]){
		dfs(lstrd,lstbl,nnisth+1,qdh+lstrd);
	}else dfs(a[nnisth],lstbl,nnisth+1,qdh);
	if(lstbl==a[nnisth]){
		dfs(lstrd,lstbl,nnisth+1,qdh+lstbl);
	}else dfs(lstrd,a[nnisth],nnisth+1,qdh);
}
inline void solve(){
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,1,0LL);
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}
