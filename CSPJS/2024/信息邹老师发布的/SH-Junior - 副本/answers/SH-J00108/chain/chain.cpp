#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100009],r,c;
vector<int> S[100009];
struct edge{
	int u,v;
};
vector<edge> to[100009];
bool dfs(int u,int s,int tar,int r){				//u选s出发，通过r步到达tar 
	if (tar==s&&r==0) return true;
	bool res=false;
	for (int i=0;i<to[u].size();++i){
		if (to[u][i].u==s){
			for (int nxt=1;nxt<=n;++nxt) if (nxt!=i) res=(res||(dfs(nxt,to[u][i].v,tar,r-1)));
		}
	}
	return res;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for (int a=1;a<=T;++a){
		cin>>n>>k>>q;for (int i=1;i<=n;++i) to[i].clear();
		for (int i=1,x;i<=n;++i){
			cin>>l[i];
			S[i].clear();for (int j=0;j<l[i];++j) cin>>x,S[i].push_back(x); 
		}
		for (int i=1;i<=n;++i){
			for (int j=0;j<l[i];++j) for (int b=j+1;b<=min(j+k-1,l[i]);++b) to[i].push_back((edge){S[i][j],S[i][b]});
		}
		for (int t=1;t<=q;++t){
			cin>>r>>c;bool res=false;
			for (int s=1;s<=n;++s){
				res=res||(dfs(s,1,c,r));
			}
			cout<<res<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
