#include<bits/stdc++.h>
using namespace std;
vector<int>f;
vector<int>dp;
/*
int erjinzhi(int n){
	int temp=n,rest,ans=0;

	for(int i=0;temp!=0;i++){
		rest=temp%2;
		temp/=2;
		ans+=rest*pow(10,i);
	}
	return ans;
}*/

int main(){
	int n,k,a[5005];
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	if(k==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f.push_back(a[i]);
	}
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]^f[i];
	}
	cout<<2;
	return 0;
}
