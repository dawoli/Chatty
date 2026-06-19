#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[501],f[501],ans;
string s;
vector<long long>y(501);
bool check(){
	long long b=0;
	for(int i=1;i<=n;++i){
		b+=((b>=y[i])||(s[i-1]=='0'));
	}
	return ((n-b)>=m);
}
void dfs(int u){
	if(u>n){
		ans+=check();
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!f[i]){
			f[i]=1;
			y[u]=c[i];
			dfs(u+1);
			f[i]=0;
		}
	}
}
int main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
