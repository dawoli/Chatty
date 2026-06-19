#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
int a[100100][3];
int num[5];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		memset(num,0,sizeof num);
		memset(a,0,sizeof a);
		priority_queue<int> pq[5];
		scanf("%lld",&n);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= 3;j++) scanf("%lld",&a[i][j]);
		}
		int temp[3]={0};
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= 3;j++) temp[j]=a[i][j];
			sort(temp+1,temp+4);
			int mx1 = temp[3];//Max
			int mx2 = temp[2];//Second Max
			ans += mx1;
			if(mx1==a[i][1]) pq[1].push(mx2-mx1);
			else if(mx1==a[i][2]) pq[2].push(mx2-mx1);
			else pq[3].push(mx2-mx1);
		}
		int MX = max(num[1],max(num[2],num[3]));
		for(int i = 1;i <= 3;i++) {
			if(pq[i].size()>n/2) {
				int sz = pq[i].size();
				for(int j = 1;j <= sz-n/2;j++) {
					int now = -pq[i].top();
					ans -= now;
					pq[i].pop();
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
只可能有一种社团人满n/2
且这些满掉的人一定可以任意地放进其他社团
复杂度：O(3nlogn) 
*/
