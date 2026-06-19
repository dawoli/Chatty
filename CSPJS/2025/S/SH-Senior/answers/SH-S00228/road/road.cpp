#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=1e18;
map<pair<int,int>,int> w,wc;
vector<int> r[15];
int c[15];
bool cgc[15],f[15];
void dfs(int city_num,int nowc,long long cost){
	if(cost>=ans)
	    return ;
	if(city_num==n){
		//cout<<cost<<endl;
		ans=cost;
		return ;
	}
	if(cgc[nowc]==0){
		for(int i=0;i<r[nowc].size();i++){
			int nextc=r[nowc][i];
			if(f[nextc]==0){
				f[nextc]=1;
				//cout<<nextc<<"<->"<<nowc<<' '<<w[make_pair(nextc,nowc)]<<endl;
				dfs(city_num+1,nextc,cost+w[make_pair(nextc,nowc)]);
				dfs(city_num+1,nowc,cost+w[make_pair(nextc,nowc)]);
				f[nextc]=0;
			}
		}
	}
	
	if(nowc<=k){
		if(cgc[nowc]==0){
			cost+=c[nowc];
			cgc[nowc]=1;
		}
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				f[i]=1;
				//cout<<i<<"<->"<<nowc<<' '<<wc[make_pair(i,nowc)]<<endl;
				dfs(city_num+1,i,cost+wc[make_pair(i,nowc)]);
				dfs(city_num+1,nowc,cost+wc[make_pair(i,nowc)]);
				f[i]=0;
			}
		}
		cgc[nowc]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		w[make_pair(u,v)]=wt;
		r[u].push_back(v);
		w[make_pair(v,u)]=wt;
		r[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		int wt;
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>wt;
			wc[make_pair(j,i)]=wt;
			wc[make_pair(i,j)]=wt;
		}
	}
	f[1]=1;
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
