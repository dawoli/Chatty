#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
vector<int> s[100005];
int dp[105][200005];
int main(){
	freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l;
			cin>>l;
			for(int j=1;j<=l;j++){
				int u;
				cin>>u;
				s[i].push_back(u);
				if(u==1){
					dp[0][u]=1;
				}
			}
		} 
		for(int i=1;i<=100;i++){
			for(int u=1;u<=n;u++){
				for(int v=0;v<s[u].size();v++){
					if(v>1){
				        dp[i][s[u][v]]=max(dp[i][s[u][v]],dp[i-1][s[u][v-1]]);
				    }
				}
			}
		}
		for(int i=1;i<=q;i++){
			int r,c;
			cin>>r>>c;
			cout<<(dp[r][c]?1:0)<<endl;
		}
		for(int i=0;i<=100;i++){
			for(int u=1;u<=n;u++){
				for(int v=0;v<s[u].size();v++){
				    dp[i][s[u][v]]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			while(s[i].size()>1){
				s[i].pop_back();
			}
		}
	}
	return 0;
}
