#include <iostream>
#include <algorithm>
using namespace std;

int n,a[5005],f[5005][50005],sum,sa[5005];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1); 
	for (int i=1;i<n;i++) {
		sa[i]=sa[i-1]+a[i];
		sum+=a[i];
		f[i][a[i]]++;
	}
	for (int i=1;i<n;i++) {
		for (int j=1;j<=sum;j++) {
			if (a[i]<j) {
				f[i][j]+=f[i-1][j-a[i]];
			}
			f[i][j]+=f[i-1][j];
			f[i][j]%=998244353;
		}
	}
	int ans=0;
	for (int i=3;i<=n;i++) {
		for (int j=a[i]+1;j<=sa[i-1];j++) {
			ans+=f[i-1][j];
			ans%=998244353;
		}
	}
	cout << ans;
} 
