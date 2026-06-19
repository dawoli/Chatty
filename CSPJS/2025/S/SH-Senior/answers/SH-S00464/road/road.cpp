#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+20,K=15;
vector<pair<long long,long long>> b[N];
vector<pair<long long,long long>> oldb[N];
long long c[K];
long long ans=1e18;
bool avi[N];
long long dis[N];
bool vis[N];
long long n,m,k;
long long cost=0;
/*bool cmp(pair<long long,pair<long long,long long>> x,pair<long long,pair<long long,long long>> y){
	if(x.first!=y.first)return x.first<y.first;
	else return x.second<y.second;
}*/
long long dij(){
	long long cnt=0;
	for(long long i=1;i<=n+k;i++)dis[i]=1e18,vis[i]=0;
	priority_queue<vector<pair<long long,long long>>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> Q;
	dis[1]=0;
	Q.push({0,1});
	while((!Q.empty())){
		if(cnt+cost>=ans)return ans;
		pair<long long,long long> now=Q.top();
		Q.pop();
		if(vis[now.second])continue;
		vis[now.second]=1;
		cnt+=now.first;
		long long u=now.second;
		//cout<<"?????"<<now.first<<' '<<now.second.first<<' '<<now.second.second<<endl;
		for(pair<long long,long long> v:b[u])if(avi[v.first] && !vis[v.first]){
			if(v.second<dis[v.first]){
				dis[v.first]=v.second;
				//cout<<v.first<<endl;
				Q.push({v.second,v.first});
			}
		}
	}
	//cout<<cnt<<endl;
	return cnt;
}
void dij2(){
	for(long long i=1;i<=n;i++)dis[i]=1e18,vis[i]=0;
	priority_queue<vector<pair<pair<long long,long long>,pair<long long,long long>>>,vector<pair<pair<long long,long long>,pair<long long,long long>>>,greater<pair<pair<long long,long long>,pair<long long,long long>>>> Q;
	dis[1]=0;
	Q.push({{0,1},{-1,-1}});
	while(!Q.empty()){
		pair<pair<long long,long long>,pair<long long,long long>> now=Q.top();
		Q.pop();
		if(vis[now.first.second])continue;
		if(now.second.first!=-1)b[now.second.first].push_back({now.first.second,now.first.first});
		if(now.second.first!=-1)b[now.first.second].push_back({now.second.first,now.first.first});
		vis[now.first.second]=1;
		//cnt+=now.first.first;
		long long u=now.first.second;
		//cout<<"?????"<<now.first<<' '<<now.second.first<<' '<<now.second.second<<endl;
		for(long long i=0;i<(long long)oldb[u].size();i++){
			pair<long long,long long>v=oldb[u][i];
			if(avi[v.first] && !vis[v.first]){
				if(v.second<dis[v.first]){
					dis[v.first]=v.second;
					//cout<<v.first<<endl;
					Q.push({{v.second,v.first},{u,i}});
				}
			}
		}
	}
	//cout<<cnt<<endl;
	return;
}
void dfs(long long k){
	if(k){
		avi[n+k]=1;
		cost+=c[k];
		dfs(k-1);
		avi[n+k]=0;
		cost-=c[k];
		if(c[k])dfs(k-1);
	}
	else ans=min(ans,(cost+dij()));
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	long long u,v,w;
	for(long long i=1;i<=n;i++)avi[i]=1;
	for(long long i=1;i<=m;i++){
		cin>>u>>v>>w;
		oldb[u].push_back({v,w});
		oldb[v].push_back({u,w});
	}
	dij2();
	long long sum=0;
	for(long long i=1;i<=n;i++){
		dis[i]=1e18;
		for(pair<long long,long long> bs:b[i])dis[i]=min(dis[i],bs.second);
		sum=max(dis[i],sum);
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>w;
			u=i+n;
			v=j;
			if(w<=sum)b[u].push_back({v,w});
			if(w<=sum)b[v].push_back({u,w});
		}
	}
	dfs(k);
	cout<<ans<<endl;
	return 0;
}

