#include<bits/stdc++.h>
using namespace std;
vector<int>a[10000];
int x[10000][10000];
bool b[110025];
int n,m,k;
int kk[11][10005],ans;
void dfs(int mo,int d,int ji){
	if(ji==n){
		ans=min(ans,mo);
	}
	for(int i:a[d]){
		if(!b[i]){
			b[i]=true;
			dfs(mo+x[d][i],i,ji+1);
			b[i]=false;
		}
		else{
			dfs(mo+x[d][i],i,ji);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int p,q,r;
		scanf("%d",&p);
		scanf("%d",&q);
		scanf("%d",&r);
		cin>>p>>q>>r;
		a[p].push_back(q);
		a[q].push_back(q);
		x[p][q]=r;
		x[q][p]=r;
	} 
	for(int i=1;i<=k;i++){
		cin>>kk[i][0];
		for(int j=1;j<=n;j++){
			scanf("%d",&kk[i][j]);
		}
	}
	dfs(0,1,1);
	cout<<ans;
	return 0;
}
