#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int T;
int n,k,q,r,c;
bool ans;
vector<int> to[N];
vector<int> num[N];
int side[N];
void dfs(int u,int nm,int nlen,int round){ 
   	if (nlen > k || round > r) return;
	if (nlen > 1 && u == c && round == r){
		ans = 1;
		return;
	}
	if (ans == 1) return;
	
	for (int i = 0;i < (int)(to[u].size());i++){
		int v = to[u][i];
		if (num[u][i] == nm) dfs(v,nm,nlen+1,round);
		else dfs(v,num[u][i],2,round+1);
	}

}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while (T--){ 
		ans = 0;
		for (int i = 0;i < N;i++){
			to[i].clear();
			num[i].clear();
		}
		cin>>n>>k>>q;
		for (int i = 1;i <= n;i++){
			int l;
			cin>>l;
			for (int j = 1;j <= l;j++){
				cin>>side[j];
			}
			for (int j = 1;j < l;j++){
				to[side[j]].push_back(side[j+1]);
				num[side[j]].push_back(i);
			}
		}
		for (int i = 1;i <= q;i++){
			ans = 0;
			cin>>r>>c;
			dfs(1,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
