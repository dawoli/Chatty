#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool op=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if((i>=1&&a[i]!=a[i-1])||a[i]!=1) op=0;
	}
	if(op&&k==1){
		cout<<(n/3+(n%3==2));
		return 0;
	}/*
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			dp[i][j]=a[j];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			dp[i][j]^=dp[i][j-1];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			cout<<dp[i][j]<<endl;
	}*/
	int tmp=a[0],cnt=0;
	for(int i=0;i<n;i++){
		if(tmp==k){
			cnt++;
			tmp=a[++i];
			continue;
		}
		tmp^=a[i+1];
	}
	cout<<cnt;
	return 0;
}
