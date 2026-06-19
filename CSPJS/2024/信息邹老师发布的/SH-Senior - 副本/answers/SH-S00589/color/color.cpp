#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int tong[1000009];
int arr[200009];
int dp[200009];
ll ans=0;
ll temp=0;
int T=0;
int flag[200009];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<1000008;i++){
			tong[i]=-1;
		}
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(i>=1&&arr[i]==arr[i-1]){
				temp+=arr[i];
				continue;
			}
			if(tong[arr[i]]>=0){
				dp[i]=max(dp[i-1],dp[tong[arr[i]]]+arr[i]+arr[tong[arr[i]]+1]*flag[tong[arr[i]]+1]);
				if(dp[i]!=dp[i-1])flag[i]=1;
			}
			else dp[i]=dp[i-1];
			tong[arr[i]]=i;
		}
		cout<<dp[n-1]+temp<<endl;
	} 
	return 0;
}
