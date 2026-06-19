#include <bits/stdc++.h> 
using namespace std;
#define int long long

const int mod = 998244353;

int n,a[5005],ans,sum,maxn;

void dfs(int step,int x){
	if(step >= 3&&sum>maxn*2){
		ans = (ans+1)%mod;
	}
	for(int i=x+1;i <= n;i++){
		sum += a[i];
		int mn = maxn;
		maxn = max(maxn,a[i]);
		dfs(step+1,i);
		sum -= a[i];
		maxn = mn;
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
