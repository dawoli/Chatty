#include<iostream>
#include<algorithm>
using namespace std;
int n,ans=0,maxdp=0,sum=0;
int main(){
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int dp[sum+10000]={};
	dp[0]=1;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=a[i]+1;j<=maxdp;j++){
			ans+=dp[j];
			ans%=998244353;
		}
		for(int j=maxdp;j>-1;j--){
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=998244353;
		}
		maxdp+=a[i];
	}
	cout<<ans;
}
