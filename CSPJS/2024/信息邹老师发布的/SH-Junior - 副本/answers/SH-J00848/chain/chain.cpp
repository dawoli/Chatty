#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define N 222222
int t,n,k,q,m,ind[N],cnt;
bool dp[101][1001][2002],b[101][2002];
vector<int>s[N];
map<int,vector<pair<int,int> > >lind;
void dfs(int id,int jd,int kd){
//	cerr<<id<<' '<<jd<<' '<<kd<<endl;
	if(id>100)return;
	if(dp[id][jd][kd])return;
	dp[id][jd][kd]=1;
	for(auto i:lind[kd])
		if(i.first!=jd)
			for(int l=i.second+1;l<min(i.second+k,(int)s[i.first].size());l++)
				dfs(id+1,i.first,s[i.first][l]);
}
int main(){
	open("chain");
	cin>>t;
	while(t--){
		memset(ind,0,sizeof(ind));
		memset(dp,0,sizeof(dp));
		memset(b,0,sizeof(b));
		lind.clear();
		cnt=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			s[i].clear();
			cin>>m;
			while(m--){
				int a;
				cin>>a;
				if(!ind[a])ind[a]=++cnt;
				s[i].push_back(ind[a]);
				lind[ind[a]].push_back({i,s[i].size()-1});
			}
		}
		dfs(0,0,1);
		for(int i=0;i<=100;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=cnt;k++)
					b[i][k]|=dp[i][j][k];
		while(q--){
			int r,c;
			cin>>r>>c;
			cout<<b[r][ind[c]]<<endl;
		}
	}
}
