#include<bits/stdc++.h>
using namespace std;
int n,a[5003];
int cho(int no,int ans,int maxn){
	if(no==n+1) {
		if(ans>maxn*2) return 1;
		else return 0;
	}
	return cho(no+1,ans,maxn)%998244353+cho(no+1,ans+a[no],max(maxn,a[no]))%998244353;
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<cho(1,0,0)%998244353;
	return 0;
}
