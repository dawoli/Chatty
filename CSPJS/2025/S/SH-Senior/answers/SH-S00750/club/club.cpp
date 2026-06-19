#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[3];
int a[100005][3];
int ans[100005];
int change[100005];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--) {
		for(int i = 0; i < 3; i++) cnt[i] = 0;
		scanf("%d",&n);
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			int maxn = 0;
			for(int j = 0; j < 3; j++) {
				scanf("%d",&a[i][j]);
				if(a[i][j] > maxn) {
					maxn = a[i][j];
					ans[i] = j;
				}
			}
			cnt[ans[i]]++;
			sum += a[i][ans[i]];
		}
		for(int i = 0; i < 3; i++) {
			if(cnt[i] > n / 2) {
				int cur = 0;
				for(int j = 1; j <= n; j++) {
					if(ans[j] == i) {
						cur++;
						change[cur] = 1e9;
						for(int k = 0; k < 3; k++) {
							if(i == k) continue;
							change[cur] = min(change[cur],a[j][i] - a[j][k]);
						}
					}
				}
				sort(change+1,change+cur+1);
				for(int j = 1; j <= cnt[i]-n/2; j++) {
					sum -= change[j];
				}
			}
		}
		printf("%d\n",sum);
	}
} 
