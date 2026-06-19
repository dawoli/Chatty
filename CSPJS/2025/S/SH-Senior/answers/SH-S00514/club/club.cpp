#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N][7];
int vis[N];
int cnt[7];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		int ans = 0;
		memset(cnt,0,sizeof cnt);
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int maxn = max(max(a[i][1],a[i][2]),a[i][3]);
			for(int j = 1;j<=3;j++){
				if(a[i][j] == maxn){
					cnt[j] ++;ans += maxn;
					vis[i] = j;break;
				}
			}
		}
		if(cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2){
			printf("%d\n",ans);continue;
		}
		int now = 0;
		if(cnt[1] > n/2) now=1;
		if(cnt[2] > n/2) now=2;
		if(cnt[3] > n/2) now=3;
		vector<int> tmp;
		for(int i = 1;i<=n;i++){
			if(vis[i] == now){
				tmp.push_back(min(a[i][now]-a[i][now%3+1],a[i][now]-a[i][(now+1)%3+1]));
			}
		}
		sort(tmp.begin(),tmp.end());
		for(int i = 0;i<(cnt[now]-n/2);i++){
			ans -= tmp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
