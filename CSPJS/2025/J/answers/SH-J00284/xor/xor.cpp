#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],lst=1;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		dp[i]=dp[i-1];
		for(int j=i;j>=lst;j--){
			x=x^a[j];
			if(x==k){
				dp[i]++;lst=i+1;break;
			}
		}
	}
	cout <<dp[n]<<endl;
	return 0;
}
