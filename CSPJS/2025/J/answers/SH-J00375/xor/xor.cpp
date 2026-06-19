#include<iostream>
using namespace std;
unsigned preors[600000];
unsigned ranges[600000];
int dp[600000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>preors[i];
		preors[i]^=preors[i-1];
		for(int j = i;j > 0;j--){
			int x = preors[i]^preors[j-1];
			if(x==k){
				ranges[i]=j;
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(ranges[i] == 0){
			dp[i]=dp[i-1];
			continue;
		}
		dp[i]=max(dp[ranges[i]-1]+1,dp[i-1]);
//		cout<<i<<" "<<dp[i]<<" "<<ranges[i]<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
} 
