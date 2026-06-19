#include<bits/stdc++.h>
using namespace std;

long long n,q,m,ans,vis[200010];
string s[200010][3],t[3];

void dfs(long long pos,string g){
	if(g.substr(0,pos)!=t[2].substr(0,pos)) return;
	if(g==t[2]){
		ans++;
		return;
	}
	dfs(pos+1,g);
	for(int i=1;i<=n;i++){
		int f=s[i][1].size();
		if(g.substr(pos,f)==s[i][1]&&vis[i]==0){
			vis[i]=true;
			dfs(pos+f,g.substr(0,pos)+s[i][2]+g.substr(pos+f,m-pos-f));
			vis[i]=false;
		}
	}
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t[1]>>t[2];
		m=t[1].size();
		ans=0;
		dfs(0,t[1]);
		cout<<ans<<endl;
	}
}
