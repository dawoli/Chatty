#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int T;
int S[MAXN];
int n,k,q,r,c;
bool dfs(int C,int cntK,int cntR){
	if(S[C]==0) return 0;
	if(cntK>=k) return 0;
	if(cntR>r) return 0;
	if(C==c) return 1;
	if(S[C]>=2 && cntK>=2) return (dfs(C+1,1,cntR+1) || dfs(C+1,cntK+1,cntR));
	else return dfs(C+1,cntK+1,cntR);
}
void solve(){
	memset(S,0,sizeof(S));
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int s;
			cin>>s;
			S[s]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r>>c;
		cout<<dfs(1,1,1)<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
