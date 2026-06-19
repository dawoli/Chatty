#include<bits/stdc++.h>
using namespace std;
int t,n;
long long dp[100010];
int ans1=0,ans2=0,ans3=0,k=0,p;
struct node{
	int m1,m2,m3;
}a[100010];
int sum1(int i){
	if(ans1<=k){
		return dp[i-1]+a[i].m1;
	}else{
		return 0;
	}
}int sum2(int i){
	if(ans2<=k){
		return dp[i-1]+a[i].m2;
	}else{
		return 0;
	}
}int sum3(int i){
	if(ans3<=k){
		return dp[i-1]+a[i].m3;
	}else{
		
		return 0;
		
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans1=0,ans2=0,ans3=0;
		cin>>n;
		k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
		}

		for(p=1;p<=n;p++){
			int i=p;
			
			dp[i]=max(sum1(i),max(sum2(i),sum3(i)));
			if(dp[i]==sum1(i)){
				ans1++;
			}if(dp[i]==sum2(i)){
				ans2++;
			}if(dp[i]==sum3(i)){
				ans3++;
			}
			
		}
		cout<<dp[n]<<endl;
		for(int i=1;i<=n;i++){
			dp[i]=0;
		
		}

		
	}
} 
