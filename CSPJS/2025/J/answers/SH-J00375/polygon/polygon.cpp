#include<iostream>
#include<algorithm>
#define R 998244353
unsigned dp[4][26000000];
unsigned k[6000];
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	unsigned long long n,sum=0,cnt = 0;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>k[i];
	}
	sort(k,k+n);
	for(int i = 0;i < n;i++){
		sum+=k[i];
		for(long long j = sum;j >= 0;j--){
			dp[0][j]+=(j==k[i]);
			if(j>=k[i])dp[1][j]+=dp[0][j-k[i]];
			if(j>=k[i])dp[2][j]+=dp[1][j-k[i]]+dp[2][j-k[i]];
			if(j>=k[i])dp[3][j]=dp[1][j-k[i]]+dp[2][j-k[i]];
			dp[0][j]%=R;
			dp[1][j]%=R;
			dp[2][j]%=R;
			dp[3][j]%=R;
//			cout<<i<<","<<j<<":"<<k[i]<<"+"<<dp[0][j]<<"&"<<dp[1][j]<<"&"<<dp[2][j]<<endl;
		}
		for(long long j = k[i]*2+1;j <= sum;j++){
//			cout<<j<<":"<<dp[3][j]<<endl;
			cnt+=dp[3][j];
			cnt%=R;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
