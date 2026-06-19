#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n;
int cnt=0;
vector<int> a;
vector<bool> vis;
vector<int> tmp;
void dfs(int now,int step){
	if(step==n+1){
		int sum=0;
		for(auto i:tmp){
			sum+=i;
		}
		if(sum>(tmp[tmp.size()-1]*2)){
			cnt++;
			cnt%=MOD;
//			for(auto j:tmp) cerr<<j<<" ";
//			cerr<<"\n";
		}
		return ;
	}
	if(tmp.size()>=3){
		int sum=0;
		for(auto i:tmp){
			sum+=i;
		}
		if(sum>(tmp[tmp.size()-1]*2)){
			cnt++;
			cnt%=MOD;
//			for(auto j:tmp) cerr<<j<<" ";
//			cerr<<"\n";
		}
	}
	for(int i=now;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			tmp.push_back(a[i]);
			dfs(i,step+1);
			tmp.pop_back();
			vis[i]=0;
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a=vector<int>(n+1);
	vis=vector<bool>(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	int st=clock();
	dfs(1,1);
	cout<<cnt<<endl;
	return 0;
}
