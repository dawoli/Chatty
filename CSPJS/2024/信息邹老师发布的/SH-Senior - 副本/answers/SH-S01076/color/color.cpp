#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N = 2e5+7;
typedef long long ll;
void quick(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}
ll A[N],dp[2][N];
int n;
ll F(int i,int j){
	if(A[i]==A[j])return A[j];
	return 0;
}
void solve(){
	std::memset(A,0,sizeof(A));
	std::cin>>n;
	for(int i=1;i<=n;++i)std::cin>>A[i];
	dp[1][1]=dp[0][1]=0;
	for(int i=2;i<=n;++i){
		dp[1][i]=dp[0][i]=0;
		dp[1][i]=std::max(dp[1][i-1],dp[0][i-1])+F(i-1,i);
		ll sum=0;
		for(int j=i-1;j>1;--j){
			if(j<=i-2)sum+=F(j,j+1);
			dp[0][i]=std::max(dp[0][i],dp[0][j]+sum+F(j-1,i));
		}
		if(i>2)sum+=F(1,2);
		dp[0][i]=std::max(dp[0][i],sum);
//		std::cout<<dp[0][i]<<" "<<dp[1][i]<<std::endl;
	}
	std::cout<<std::max(dp[0][n],dp[1][n])<<"\n";
}
int main(){
	std::freopen("color.in","r",stdin);
	std::freopen("color.out","w",stdout);
	quick();
	int T;
	std::cin>>T;
	while(T--)solve();
	return 0;
}
