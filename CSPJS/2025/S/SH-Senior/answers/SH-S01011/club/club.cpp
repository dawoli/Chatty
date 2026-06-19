#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N][5],n;
long long ans;
vector<int>minloss[5];
void solve()
{	
	for(int i = 1;i <= 3;i++)
		minloss[i].clear();
	scanf("%d",&n);
	ans = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		ans += max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			minloss[1].push_back(a[i][1] - max(a[i][2],a[i][3]));
		} else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			minloss[2].push_back(a[i][2] - max(a[i][1],a[i][3]));
		} else {
			minloss[3].push_back(a[i][3] - max(a[i][1],a[i][2]));
		}
	}
	for(int i = 1,sz;i <= 3;i++) {
		sz = minloss[i].size();
		if(sz > n / 2) {
			sort(minloss[i].begin(),minloss[i].end());
			sz = sz - n / 2;
			for(int j = 0;j < sz;j++)
				ans -= minloss[i][j];
		}
	}
	printf("%lld\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	fclose(stdin),fclose(stdout);
	return 0;
}
