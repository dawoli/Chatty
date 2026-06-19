#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],f=1;
long long C[5005][5005],cnt;
void dfs(int dep,int mx,int sum){
	if(dep>n){
		if(sum>2*mx) cnt=(cnt+1)%MOD;
		return ;
	}
	dfs(dep+1,a[dep],sum+a[dep]);
	dfs(dep+1,mx,sum);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		long long ans=0;
		C[0][1]=1;
		for(int i=1;i<=n+1;i++){
			C[i][1]=1;
			for(int j=2;j<=i;j++){
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+C[n+1][i+1])%MOD;
		}
		cout<<ans;
		goto end;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<cnt;
	end:;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
