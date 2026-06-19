#include <bits/stdc++.h>
using namespace std;
struct Node{int id,a[4];}a[1000005];
bool cmp(Node x,Node y){return (max(x.a[1],max(x.a[2],x.a[3])) - min(x.a[1],min(x.a[2],x.a[3]))) > (max(y.a[1],max(y.a[2],y.a[3])) - min(y.a[1],min(y.a[2],y.a[3])));}
int T,n,cnt[4],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--){
		cin >> n,memset(cnt,0,sizeof(cnt)),ans = 0;
		for (int i = 1;i <= n;i++) for (int j = 1;j <= 3;j++) cin >> a[i].a[j];
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1;i <= n;i++){
			int mx = -1,mxid = 0;
			for (int j = 1;j <= 3;j++) if (a[i].a[j] > mx) mxid = j,mx = a[i].a[j];
			if (cnt[mxid] < n / 2) cnt[mxid]++,ans += mx;
			else{
				a[i].a[mxid] = -1,mx = -1,mxid = 0;
				for (int j = 1;j <= 3;j++) if (a[i].a[j] > mx) mxid = j,mx = a[i].a[j];
				if (cnt[mxid] < n / 2) cnt[mxid]++,ans += mx;
				else{
					a[i].a[mxid] = -1,mx = -1,mxid = 0;
					for (int j = 1;j <= 3;j++) if (a[i].a[j] > mx) mxid = j,mx = a[i].a[j];
					if (cnt[mxid] < n / 2) cnt[mxid]++,ans += mx;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
