#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,mx=-1;
	vector<int> nums;
	cin>>T;
	for(int zzz=0;zzz!=T;zzz++){
		int n;
		cin>>n;
		mx=max(mx,n);
		nums.push_back(n);
	}
	long long dp[mx+5];
	for(int i=0;i!=mx+5;i++){
		dp[i]=INT_MAX;
	}
	dp[2]=1;
	dp[3]=7;
	dp[4]=4;
	dp[5]=2;
	dp[6]=0;
	dp[7]=8;
	for(int i=8;i!=mx+5;i++){
		for(int k=1;k!=i;k++){
			long long a,b;
			a=dp[i-k];
			if(a==0){
				a=6;
			}
			b=dp[k];
			long long temp=b;
			if(temp==0){
				a*=10;
			}
			while(temp!=0){
				temp/=10;
				a*=10;
			}
			dp[i]=min(dp[i],a+b);
		}
	}
	for(int i=0;i!=T;i++){
		if(dp[nums[i]]==INT_MAX){
			cout<<-1<<endl;
		}
		else{
			if(nums[i]==6){
				cout<<6<<endl;
			}
			else{
				cout<<dp[nums[i]]<<endl;
			}
		}
	}
	return 0;
} 
