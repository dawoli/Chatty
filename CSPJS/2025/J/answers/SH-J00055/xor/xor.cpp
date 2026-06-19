#include<iostream>
#include<map>
using namespace std;
const int N=5e5;
int n,k,a,sum,dp[N+1];
map<int,int>m;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr); 
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	cin>>n>>k,m[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum^=a;
		dp[i]=max(dp[i-1],m.count(sum^k)?dp[m[sum^k]]+1:0);
		m[sum]=i;
	}
	cout<<dp[n];
	return 0;
} 
