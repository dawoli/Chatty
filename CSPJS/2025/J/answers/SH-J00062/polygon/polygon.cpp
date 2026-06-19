#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],sum[2000005],mod = 998244353,flag = 1,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) flag = 0;
	}
	if(flag==1){
		ans = 1;
		for(int i = 1;i<=n;i++) ans = (2*ans)%mod;
		ans+=mod-1-n-(n*(n-1)/2);
		cout << (ans%mod);
	}
	else if(n<=20){
		sort(a+1,a+n+1);
		for(int i = 3;i<=n;i++){
			if(i==3){
				sum[1] = a[1]+a[2];
				if(sum[1]>a[3]) ans++;
			}
			else{
				for(int j = (1<<(i-2))-i+2;j<=(1<<(i-1))-2*i+2;j++) sum[j] = sum[j-(1<<(i-2))+i-1]+a[i-1];
				for(int j = (1<<(i-1))-2*i+3;j<=(1<<(i-1))-i;j++) sum[j] = a[j-(1<<(i-1))+2*i-2]+a[i-1];
				sort(sum+1,sum+(1<<(i-1))-i+1);
				for(int j = 1;j<=(1<<(i-1))-i;j++){
					if(sum[j]>a[i]){
						ans+=(1<<(i-1))-i+1-j;
						break;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}
