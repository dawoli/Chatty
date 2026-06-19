#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> bank[100100];
vector<int> flag[110][100100];
int n,k,q;
bool dfs(int l,int t,int p){
	if(l==0){
		return (t==1);
	}
	bool s = 0;
	for(int i = 0;i < n;i++){
		if(i==p) continue;
		for(int j = 0;j < bank[i].size();j++){
			if(bank[i][j]==t){
				for(int o = j-1;o > j-k&&o>=0;o--){
					if(flag[l-1][i][o]==-1)flag[l-1][i][o]=dfs(l-1,bank[i][o],i);
					s = s||flag[l-1][i][o];
					if(s) return 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i = 0;i < n;i++){
			int l;
			cin>>l;
			for(int j = 0;j < l;j++){
				int num;
				cin>>num;
				bank[i].push_back(num);
				for(int r = 0;r < 105;r++){
					flag[r][i].push_back(-1);
				}
			}
		}
		for(int i = 0;i < q;i++){
			int r,c;
			cin>>r>>c;
			bool s = 0;
			for(int i = 0;i < n;i++){
				s=s||dfs(r,c,i);
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
