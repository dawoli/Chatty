#include<bits/stdc++.h>
using namespace std;
int a[500001],s[500001];
struct area{
	int l,r;
}b[500001];
int dp[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	if(a[1]==k){
		dp[1]=1;
		b[1].l=1,b[1].r=1;
	}
	else dp[1]=0;
	for(int i=2;i<=n;i++){
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
			b[dp[i]].l=i,b[dp[i]].r=i;
		}
		else{
			if(b[dp[i-1]].r+1==i) dp[i]=dp[i-1];
			else{
				bool flag=0;
				for(int j=b[dp[i-1]].r+1;j<=i-1;j++){
					if((s[i]^s[j-1])==k){
						flag=1;
						dp[i]=dp[i-1]+1;
						b[dp[i]].l=j,b[dp[i]].r=i;
						break;
					}
				}
				if(!flag) dp[i]=dp[i-1];
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
}
