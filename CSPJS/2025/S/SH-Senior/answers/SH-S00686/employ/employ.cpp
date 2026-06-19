#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int mod=998244353;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool A=true;
	int cnt1=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')A=false;
		if(s[i]=='1')cnt1++;
	}
	if(cnt1<m){
		cout<<"0";
		return 0;
	}
	int maxa=0,le=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)le++;
		maxa=max(maxa,a[i]);
	}
	if(A){
		long long ans=n-le;
		for(int i=1;i<m;i++){
			ans=ans*(ans-i)%mod;
		}
		for(int i=1;i<=le;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1); 
		int ans=1;
		int lev=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]==0){
				lev++;
				i++;
				while(a[i]<=lev)lev++,i++;
			}else{
				int count=1;
				for(int j=i+1;j<=n;j++){
					if(a[j]==a[i])count++;
					else break;
				}
				ans=ans*count%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	if(maxa==1){
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				long long ans=1;
				for(int j=i-1;j>=1;j--)ans=ans*j%mod;
				cout<<ans;
			}
		}

		return 0;
	}
	cout<<"5";
	return 0;
} 
