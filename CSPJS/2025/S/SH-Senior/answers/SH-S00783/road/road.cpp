#include<bits/stdc++.h>
using namespace std;
long long n,m,k,mp[11111][11111],ans,dp[11111][11111];
int main(){
	freopen(" road.in","r",stdin);
	freopen(" road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mp[i][j]=1e9;
			dp[i][j]=1e9;
		}
	}
	
	long long u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
	}
	
	for(int i=0;i<k;i++){
		long long a[111111];
		cin>>w;
		for(int l=0;l<n;l++){
			cin>>a[i];
		}
		for(int l=0;l<n;l++){
			for(int j=l+1;j<n;j++){
				if(w+a[l]+a[j]<mp[l][j]){
					mp[l][j]=w+a[l]+a[j];
				}	
			}
		}
		
	}
	queue<long long>q;
	q.push(u);
	for(int i=0;i<n;i++){
	
		for(int l=0;l<n;l++){
			if(mp[u][l]!=1e9) {
				q.push(l);
			}
			if(mp[i][l]!=1e9){
				ans+=mp[u][l];
				cout<<1;
			}
		}
	}
	
	while(!q.empty()){
		long long x=q.front();
		q.pop();
		for(int l=0;l<n;l++){
			for(int j=0;j<n;j++){
				mp[l][j]=min(mp[l][j],mp[x][l]+mp[l][j]);
				if(mp[l][j]==mp[x][l]+mp[l][j]){
					q.push(l);
					q.push(j);
				}
			}
			
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
