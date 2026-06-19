#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int l;
int s[200001];
vector<int>G[100001];
int dis[200001];
int mod[200001];
int vis[200001];
queue<int>Q;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
    	memset(G,0,sizeof(G));
    	memset(dis,0,sizeof(dis));
    	memset(vis,0,sizeof(vis));
    	memset(mod,0,sizeof(mod));
		cin>>n>>k>>q;
		int maxi=0;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s[j];
				maxi=max(maxi,s[j]);
				for(int x=j-k+1;x<=j-1;x++)if(x>0){
					G[s[x]].push_back(s[j]); 
				}
			}
		}
		for(int x=1;x<=maxi;x++){
			sort(G[x].begin(),G[x].end()); 
			G[x].erase(unique(G[x].begin(),G[x].end()),G[x].end());
		}
		vis[1]=1;
		Q.push(1);
		while(Q.size()){
			int u=Q.front();
			Q.pop();
			for(int v:G[u]){
				if(vis[v]==0){
					dis[v]=dis[u]+1;
					vis[v]=1;
					Q.push(v);
				}
				else{
					if(mod[v]==0){
						Q.push(v);
						mod[v]=dis[u]+1-dis[v];
					}
				}
			}
		}
		int u,v;
		while(q--){
			cin>>u>>v;
			if(v>maxi){
				cout<<0<<'\n';
			}
			else if(u==dis[v]||((mod[v]!=0)&&((u-dis[v])%mod[v]==0))){
				cout<<1<<'\n';
			}
			else cout<<0<<'\n';
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
