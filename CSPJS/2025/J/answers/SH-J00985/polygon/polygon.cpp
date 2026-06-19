#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long m = 998244353;
long long ans = 0;
void dfs(int k,int sum,int maxn,int r){
	if(k == n + 1 ){
		if(maxn*2 < sum && r>=3){
			ans ++;
			ans %= m;
		}
		return;
	}
	dfs(k+1,sum+a[k],max(maxn,a[k]),r+1);
	dfs(k+1,sum,maxn,r);
}
long long quickpow(int a,int b){
	long long ans = 1,base = a;
	while(b){
		if(b&1) ans = ans* base%m;
		b = (b >> 1);
		base = base*base %m;
	}
	return ans%m;
}
 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int maxnai = 0;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		maxnai = max(a[i],maxnai);
	} 
	//25 -> 33554106 
	if(maxnai == 1){
		ans = (quickpow(2,n) - 1 - n - ((n *(n-1))/2) + m)%m ;
		cout << ans;
		return 0;
	}
	
	dfs(1,0,0,0);
	cout << ans;
	
	/* 
	else if(n <= 500){
		long long dp[505][1010];
		long long pr[505][1010];
		int ends = maxnai * 2;
		memset(dp,0,sizof(dp));
		memset(pr,0,sizof(pr));
		for(int i = 0 ;i<=ends;i++)
			if(a[1] + a[2] + a[3] > i) dp[3][i] = 1;
		for(int i = 1;i <= 3;i++){
			for(int j = 1 ;j <= ends;j++)
				pr[i][j] = pr[i][j-1] + pr[i-1][j] - pr[i-1][j-1]  + dp[i][j];
		}
		for(int i = 4;i<=n;i++){
		 	for(int j = 0;j<=ends;j++){
		 		dp[i][j] = pr[i-1][ends]pr[i-1][j-a[i]]
			}
		}
		
		In CSP-S 2025 Yzx tried his best
		However he is poor at dp
		So Although T3,T4 He has something to finish it completely ,he finally can't manage to do it.
		Wish he luck 
		And it is the last two competion! 
		Wish Yzx a happy future With ___ !
	}
	*/ 
	return 0;
}
