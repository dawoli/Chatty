#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[5005];
int a[5005];
int cm[10005][3];
int t[5005];
int z[5005];
int k[5005];
int mod=998244353;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cm[0][0]=1;
	cm[a[1]][1]=1;
	t[0]=1;
	for(int i=1;i<=n;i++) {
		t[i]=t[i-1]*2%mod;
	}
	for(int i=1;i<=n;i++) {
		z[i]=i+1;
		k[i]=t[i]-z[i]+mod;
		k[i]%=mod;
	}
	for(int i=3;i<=n;i++) {
		int sum=0;
		for(int j=10000;j>=a[i-1];j--) {
			cm[j][1]+=cm[j-a[i-1]][0];
			cm[j][1]%=mod;
			cm[j][2]+=cm[j-a[i-1]][1];
			cm[j][2]%=mod;
			cm[j][2]+=cm[j-a[i-1]][2];
			cm[j][2]%=mod;
			if(j<=a[i]) {
				sum+=cm[j][2];
				sum%=mod;
			}
		}
		for(int j=0;j<a[i-1];j++) {
			sum+=cm[j][2];
			sum%=mod;
		}
		//cout << cm[] << endl;
		f[i]+=(k[i-1]-sum+mod)%mod;
		f[i]%=mod;
	}
	int ans=0;
	for(int i=3;i<=n;i++) {
		ans+=f[i];
		ans%=mod;
	}
	cout << ans << endl;
	return 0;
} 
