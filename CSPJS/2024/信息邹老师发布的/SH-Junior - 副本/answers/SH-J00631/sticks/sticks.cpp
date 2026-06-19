#include<bits/stdc++.h>
using namespace std;
long long t;
string dp[20];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	dp[1]="-1";
	dp[2]="1";
	dp[3]="7";
	dp[4]="4";
	dp[5]="2";
	dp[6]="6";
	dp[7]="8";
	dp[8]="10";
	dp[9]="18";
	dp[10]="22";
	dp[11]="20";
	dp[12]="28";
	dp[13]="68";
	dp[14]="88";
	while(t--){
		long long n,k;
		cin>>n;
		k=n/7-1;
		if(n<=14){
			cout<<dp[n]<<endl;
			continue;
		}
		n-=7*k;
		cout<<dp[n%14];
		for(long long i=1;i<=k;i++){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
