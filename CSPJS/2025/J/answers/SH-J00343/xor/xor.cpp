#include<bits/stdc++.h>
using namespace std;
bool flag(true);
long long n,k,a[51000],c(0);
long long need[51000];
long long dp[51000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=0;
	for (int i=1;i<=n;i++){
		flag=true;
		dp[i]=dp[i-1];
//		if (a[i]==0){
//			continue;
//		}
		if (c!=0){
			for (int j=0;j<c;j++){
				if ((a[i]^need[j])==k){
					c=0;
					dp[i]=dp[i-1]+1;
					flag=false;
					break;
				}
			}
			if (c!=0){
				for (int j=0;j<c;j++){
					need[j]^=a[i];
				}
				need[c++]=a[i];
			}
		}
		if (flag){
			if (a[i]==k){
				dp[i]=dp[i-1]+1;
				c=0;
			}
			else{
				need[c++]=a[i];
			}
		}

	}
	cout<<dp[n]<<endl;
	return 0;
}
