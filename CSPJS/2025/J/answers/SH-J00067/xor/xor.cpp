#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],cnt[30],cnt1,cnt0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt1++;
		if(a[i]==0)cnt0++;
		if(i==1)sum[i]=a[i];
		else sum[i]=sum[i-1]^a[i];
		cout<<sum[i]<<" ";
	}
	cout<<endl;
	if(cnt1==n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(i%2==0)ans+=i;
		}
		cout<<ans;
	}
	else{
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j==i){
					if(sum[j]==k){
						ans++;
					}
				}
				else if(sum[j]^sum[j-i-1]==k){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
