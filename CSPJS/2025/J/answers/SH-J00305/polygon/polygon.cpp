#include <bits/stdc++.h>
using namespace std;
int a[5000+10];
int i,x;
int js(int cnt,int mx,int s,int y,int ans){
	if(s>=x){
		if(cnt>2*mx){
			ans=ans+1;
			ans=ans%998244353;
			return ans;
		}
	}
	for(int j=y+1;j<i;j++){
		for(int k=x-s;k<x;k++){
			if(cnt>2*mx){
				ans=ans+1;
				ans=ans%998244353;
				return ans;
			}
			ans+=js(cnt+a[j],max(a[j],mx),s+k,j,ans);
		}
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0;
	cin>>x;
	for(i=1;i<=x;i++){
		cin>>a[i];
	}
	cout<<js(0,0,0,0,0);
//	cout<<9;
	return 0;
}
