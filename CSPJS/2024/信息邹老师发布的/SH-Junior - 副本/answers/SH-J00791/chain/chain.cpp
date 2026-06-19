#include<bits/stdc++.h>
using namespace std;
int ans;
void dfs(long long turn_num,long long now,long long to,long long from,long long k,vector<vector<long long>> S){
	if(turn_num==0){
		if(now==to){
			ans=1;
		}
		return;
	}
	for(long long i=0;i!=S.size();i++){
		if(i==from){
			continue;
		}
		for(long long j=0;j!=S[i].size()-1;j++){
			if(S[i][j]==now){
				for(long long temp=1;temp!=k;temp++){
					dfs(turn_num-1,S[i][j+temp],to,i,k,S);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int zzz=0;zzz!=T;zzz++){
		long long n,k,q;
		cin>>n>>k>>q;
		vector<vector<long long>> S;
		for(int i=0;i!=n;i++){
			vector<long long> temp;
			long long l;
			cin>>l;
			for(int j=0;j!=l;j++){
				long long a;
				cin>>a;
				temp.push_back(a);
			}
			S.push_back(temp);
		}
		for(int i=0;i!=q;i++){
			long long r,c;
			cin>>r>>c;
			ans=0;
			dfs(r,1,c,-1,k,S);
			cout<<ans<<endl;
		}
	}
	return 0;
} 
