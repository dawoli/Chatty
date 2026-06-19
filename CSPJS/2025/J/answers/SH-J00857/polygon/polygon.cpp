#include<bits/stdc++.h>


using namespace std;
long long lst[500005];
long long n,m,x,cnt,k,cnt1;
long long a[500005],sum[500005],dp[500005];
void dfs(int step,int mx,int sm){
	if(step==n+1){
		if(sm>(mx*2)){
			cnt++;
		
		}
		return;
	}
	dfs(step+1,mx,sm);
	dfs(step+1,a[step],sm+a[step]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(sum[n]<=1){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}

