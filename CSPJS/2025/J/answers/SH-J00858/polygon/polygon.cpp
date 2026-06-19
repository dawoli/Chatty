#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,nums[5005],ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	bool u[5005]={0};
	while(1){
		int i=0;
		while(u[i]){
			u[i]=0;
			i++;
		}
		u[i]=1;
		long long num=0,tot=0,maxn=0;
		for(i=0;i<n;i++){
			if(u[i]){
				num++;
				tot+=nums[i];
				if(nums[i]>maxn) maxn=nums[i];
			}
		}
		if(num>=3){
			if(tot>2*maxn){
				ans++;
				if(ans>998244353) ans -=998244353;
			}
		}
		if(num==n) break;
	}
	cout<<ans;
	return 0;
}
