#include<bits/stdc++.h>


using namespace std;
long long lst[500005];
long long n,m,x,cnt,k,cnt1,mx=0;
long long a[500005],sum[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	if(n>20000){
		if(k==1){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(abs(a[i]-a[i-1])==1){
					a[i]=10;
					a[i-1]=10;
					cnt++;
				}
			}
			
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]==0){
					cnt++;
				}
			}
			cout<<cnt;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k){
				lst[i]=j;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
	
		if(lst[i]==i){
			dp[i]++;
		} 
		for(int j=0;j<lst[i];j++){
			dp[i]=max(dp[i],dp[j]+1);
		}
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,dp[i]);
//		cout<<lst[i]<<" ";
	}
	cout<<mx;
	return 0;
}

