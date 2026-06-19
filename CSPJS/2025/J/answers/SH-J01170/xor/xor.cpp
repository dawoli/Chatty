#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,ans,maxx;
ll a[500010],yh[500010],dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int u=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		yh[i]=yh[i-1]^a[i]; 
		if(a[i]!=1)u=1;
	}
	for(int i=0;i<=n;i++){
		int t=i;
		ans=0;
		for(int j=i+1;j<=n;j++){
			if((yh[j]^yh[i])==k){
				ans++;
				dp[j]=max(dp[j],dp[i]+1);
				i=j;
			}dp[j]=max(dp[j],dp[j-1]);
		}
		i=t;
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
