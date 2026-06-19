#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
long long dp[2005][2005],arr[200005];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		//memset
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		long long n;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=0;j<i;j++){
				if(arr[i+1]==arr[i]){//red first
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]+arr[i]);
				}else{
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				}
				if(arr[i+1]==arr[j]){
					dp[i+1][i]=max(dp[i+1][i],dp[i][j]+arr[i+1]);
				}else{
					dp[i+1][i]=max(dp[i+1][i],dp[i][j]);
				}
			}
		}
		long long maxn=0;
		for(long long i=0;i<n;i++){
			maxn=max(maxn,dp[n][i]);
		}
		cout<<maxn<<'\n';
	}
	return 0;
}

