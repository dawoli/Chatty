#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int p=998244353;
int n,m,ans,c[N];
string s;
bool vis[N];
void dfs(int u,int cnt){
	if(u==n){
		ans+=(cnt>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		dfs(u+1,cnt+((c[i]>u-cnt)&&(s[u]=='1')));
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(0,0);
	cout<<ans<<endl;
}
