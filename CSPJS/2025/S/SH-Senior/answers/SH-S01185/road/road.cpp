#include<bits/stdc++.h>
using namespace std;
set<int> ljb[10015];
pair<int,pair<int,int> > a[1200015];
int c[15];
int aa[15][10005];
int vis[10015];
int minn[10015];
int n,m,k;
long long ans=999999999999999999;
bool ok=false;
void dfs(int now,int last){
	if(vis[now]==2){
		ok=true;
		return;
	}
	if(ok) return;
	if(vis[now]) return;
	vis[now]=2;
	for(auto i:ljb[now]) if(i!=last) dfs(i,now);
	vis[now]=1;
}
void solve(){
	long long a1=0,a2=0;
	for(int i=1;i<=m;i++){
		ljb[a[i].second.first].insert(a[i].second.second);
		ljb[a[i].second.second].insert(a[i].second.first);
		dfs(a[i].second.first,-1);
		if(ok){
			ljb[a[i].second.first].erase(a[i].second.second);
			ljb[a[i].second.second].erase(a[i].second.first);
		}
		else{
			a1++;
			a2+=a[i].first;
		}
		if(a1+1==n+k) break;
	}
	ans=min(ans,a2);
}
int main(){
	freopen("road3.in","r",stdin);
	freopen("road3.out","w",stdout);
	cin>>n>>m>>k; 
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		//ljb[x].push_back({y,z});
		//ljb[y].push_back({x,z});
		a[i]={z,{x,y}}; 
	}
	int sumk=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		sumk+=c[i];
		for(int j=1;j<=n;j++){
			cin>>aa[i][j];
		}
	}
	if(sumk==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[++m]={aa[i][j],{i,j}};
			}
		}
	}
	sort(a+1,a+1+m);
	solve();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
											   ##				 ##
											  ############		############		
											 ##	 ##		   ##  ##  ##
											##	  ##       ## ##	##
													################
														   ##
                    	     ##                            ##
###############################            ##################################
														       ##
														  	   ##
												  ###################
															   ##
														  ##   ##
															   ##
															   ##
															####															
*/
