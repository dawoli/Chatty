#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
long long n,m,c[N];
long long ans;
bool vis[N];
long long a[N],fact[N]={1};
string s;
void init(){
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%MOD;
}
void dfs(int id=1,int fail=0,int success=0){
	if(id>n){
		if(success>=m)ans=(ans+1)%MOD;
		return;
	}
	if(success>=m){
		ans=(ans+fact[n-id+1])%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&fail<c[i]){
			vis[i]=1;
			a[id]=i;
			dfs(id+1,fail+(s[id-1]=='0'),success+(s[id-1]=='1'));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	init();
	dfs();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
