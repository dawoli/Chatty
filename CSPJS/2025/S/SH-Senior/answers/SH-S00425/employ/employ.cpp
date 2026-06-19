#include<bits/stdc++.h>
using namespace std;
#define N 505
#define R 998244353
int n,m;
long long ans;
int p[N];
bool ac[N],vis[N];
void dfs(int d,int l,int s){
	if(s+n-d+1<m){
		return;}
	if(d==n+1){
		if(s>=m){ans=(ans+1)%R;}
		return;
	}
	for(int i=1;i<=n;i++) if(!vis[i]){
		vis[i]=true;
		if(l>=p[i]||!ac[d]){
			dfs(d+1,l+1,s);}
		else{
			dfs(d+1,l,s+1);}
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int ct1=0,ct2=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		ac[i]=c-'0';
		if(c-'0'==1){ct1++;}
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==0){ct2++;}
	}
	if(n-ct2<m||ct1<m){ans=0;}
	else dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
