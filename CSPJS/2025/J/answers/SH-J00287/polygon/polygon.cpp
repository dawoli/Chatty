#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ifall1=1;
long long ans,sumn,maxn,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]!=1){
			ifall1=0;
		}
	}
	if (n==3){
		if (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	if (ifall1==1){
		for (int i=1;i<=n-2;i++){
			k+=i;
			ans+=k;
			ans%=998244353;
		}
		cout << ans;
		return 0;
	}
	
	cout << ans;
	return 0;
} 
