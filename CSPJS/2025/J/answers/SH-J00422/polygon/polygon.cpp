#include<bits/stdc++.h>
using namespace std;
int dp[5010][6010];
int a[10010],gt[5010][6010],pw[5010],n,mx=0;
//si ren bang,dou shi huai dongxi!!
//pantu tewu yexinjia dajunfa 

//const int LUOGU=909552;
/*
Even harder than prob 3
20pts?

*10:11 decided to try dp; maybe backpack
*10:23 found the correct solution! maybe not afo....

Conclusion: math problems are ez ((.

*/
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//froepen("number.out","w",stdout);
	//froepen
	//rp++
	//slove()
	//mian
	cin>>n;dp[0][0]=1;pw[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];dp[i][0]=1;
		mx=max(mx,a[i]);
		pw[i]=(pw[i-1]*2)%998244353;
	}
	//mx=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=mx;j>=0;j--){
			dp[i][j]=dp[i-1][j];
			dp[i][j]=(dp[i-1][j-a[i]]+dp[i][j])%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=mx;j++){
			dp[i][j]=(dp[i][j-1]+dp[i][j])%998244353;
			if(a[i]>j)gt[i][j]=gt[i-1][j]+1;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=mx;j++)cout<<gt[i][j]<<" ";
//		cout<<'\n';
//	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans=(ans+((long long)pw[i-1]-(long long)dp[i-1][a[i]]-(long long)gt[i-1][a[i]]+998244353LL+998244353LL)%998244353)%998244353;
	}cout<<ans;
	return 0;
}
