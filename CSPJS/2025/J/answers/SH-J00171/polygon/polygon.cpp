#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
ll n,a[5010],ans,yhsj[5010][5010];
ll dfs(ll step,ll sum,ll mx){
	//if (vis[step][sum][mx]!=0)  return vis[step][sum][mx]-1;
	if (step>=n+1){
		if (sum>mx*2)  return 1;
		return 0;
	}
	ll res=0;
	res=(res+dfs(step+1,sum,mx))%mod;
	res=(res+dfs(step+1,sum+a[step],(a[step]>mx?a[step]:mx)))%mod;
	//vis[step][sum][mx]=res+1;
	return res;
}
void func(){
	yhsj[1][1]=1;
	for (int i=2;i<=n+1;i++){
		for (int j=1;j<=i;j++){
			yhsj[i][j]=yhsj[i-1][j-1]+yhsj[i-1][j];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool flag=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1)  flag=1;
	}
	if (flag)  cout<<dfs(1,0,0);
	else{
		func();
		ll ans=0;
		for (int k=3;k<=n;k++){
			ans=(ans+yhsj[n+1][k+1])%mod;
		}
		cout<<ans;
	}
	return 0;
}
