#include<bits/stdc++.h>
using namespace std;
long long int n,m,t,k,f,d,dp[105][200005],used[109][205000],r,ct[250005],e;
vector<int> mp[205000];
void dfs(int r1){
	memset(ct,0,sizeof(ct));
    if(r1>100) return;
    for(int j=1;j<=n;j++){
		for(long long int q=1;q<=mp[j].size();q++){
		for(int mk=1;mk<=min(q,k-1);mk++){
			if(dp[r1-1][mp[j][q-mk]]==1&&(ct[mp[j][q-mk]]>1||used[r1-1][mp[j][q-mk]]!=j)){
			dp[r1][mp[j][q]]=dp[r1-1][mp[j][q-mk]];
			ct[mp[j][q-mk]]++;
			used[r1][mp[j][q]]=j;
			break;
		}
	}
	}
	} 
    dfs(r1+1);
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>m;
		memset(dp,0,sizeof(dp));
		memset(mp,0,sizeof(mp));
		memset(used,0,sizeof(used));
	for(int j=1;j<=n;j++){
		cin>>d;
		for(int o=1;o<=d;o++){
		cin>>f;
		mp[j].push_back(f);
	}
	}
    for(int j=1;j<=n;j++){
		for(int o=1;o<=mp[j].size();o++){
		if(mp[j][o]==1) dp[0][1]=1,ct[1]++;
	}
	}
	dfs(1);
	for(int j=1;j<=m;j++){
		cin>>r>>e;
		cout<<dp[r][e]<<endl;
	}
}
    return 0;
}
