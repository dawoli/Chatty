#include<bits/stdc++.h>
using namespace std;
struct node{
	long long all,last;
}dp[500005];
long long n,k,a[500005],num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]={0,1};
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		num=0;
		for(int j=i;j>=dp[i].last;j--){
			num=(num^a[j]);
			if(num==k){
				dp[i].all++;
				dp[i].last=i+1;
				break;
			}
		}
	}
	cout<<dp[n].all;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
