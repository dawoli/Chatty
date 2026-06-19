#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],b[5010],dp[5010][5010];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[0]=a[0];
	for(int i=1;i<n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ans=0;
	for(int i=2;i<n;i++){
		for(int j=0;j<i-1;j++){
			if(b[j]>a[i]){
				ans+=i-j;
				cout<<ans;
				ans%=998244353;
				break;
			}
		}
	}
	cout<<ans; 
	return 0;
}

