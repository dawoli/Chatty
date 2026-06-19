#include<bits/stdc++.h>
#define ll long long
#define a first
#define b second
ll sum[510];
ll s[510];
ll c[510];
ll n,m;
ll ans;
ll MOD=998244353;
bool used[510];
void dfs(int ly){
	if(ly==m+1){
		ans=(ans+1)%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i] && sum[ly-1]<c[i]){
			used[i]=1;
			dfs(ly+1);
			used[1]=0;
		}
	}
	return;
}
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//yydz£¬¼ø¶¨ÎªÍøÂçÁ÷ 
	cin >> n >> m;
	string str;
	cin >> str;
	for(int i=0;i<n;i++){
		s[i+1]=str[i]-'0';
		sum[i+1]=sum[i]+1-s[i+1];
	}
	for(int i=1;i<=n;i++)cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}

