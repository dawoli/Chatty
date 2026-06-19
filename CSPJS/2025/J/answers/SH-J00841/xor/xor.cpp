#include <iostream>
using namespace std;

int p[1020];

const int N = 500020;
int a[N],dp[1020][1020];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool lll =0;
	int n,k,ans=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
    for (int i=1;i<=n;i++) {
    	dp[i][i] = a[i];
	}
	for (int i=1;i<n;i++) {
		for (int j=i+1;j<=n;j++) {
			dp[i][j] = dp[i][j-1] ^ a[j]; 
		}
	}
	
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			lll=0;
			if (dp[i][j] == k) {
				for (int u=1;u<=j;u++) {
					if (dp[i][u] == -1) lll = 1;
				}
				for (int u=1;u<=i;u++) {
					if (dp[u][j] == -1) lll = 1;
				}
				if (lll == 0)	{
					ans++;
					for (int w=1;w<=j;w++) {
						dp[i][w] = -1;
					} 
					for (int w=1;w<=i;w++) {
						dp[w][j] = -1;
					}
				}
			}
		}
	}
/*	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
*/
	cout << ans;
	return 0;
} 
