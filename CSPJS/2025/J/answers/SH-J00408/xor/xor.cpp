#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5+10;
int n,k;
ll a[N],s[N],dp[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i] = (s[i-1] ^ a[i]);
	}
	
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1];
		for(int j=i;j>=1;j--){
			if((s[i]^s[j-1]) == k){
				dp[i] = max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}


