#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int dp[500010];//biggest by the value of i
int lst=0;
int ans=0;
int main(){
	freopen("xor.in","r",stdin);//
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j>lst;j--){
			x=x^a[j];
			if(x==k){
				lst=i;
				ans++;
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j>0;j--){
//			if(dp[j-i])
//		}
//	}
	cout<<ans;
	return 0;
}
