#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
bool v[505];
ll ans=0;
void dfs(int x,int l){
	//cout<<x<<" "<<l<<endl;
	if(x==n+1){
		if(l>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=true;
		//cout<<c[i]<<" "<<x<<" "<<l<<endl;
		if(s[x-1]=='0'||c[i]<=x-l-1) dfs(x+1,l);
		else dfs(x+1,l+1);
		v[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

