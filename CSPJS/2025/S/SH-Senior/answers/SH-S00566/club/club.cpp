#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int t,n,cnt[3],ans;
bool ls[N];
struct Node{int id,x,w,b;}a[N];
bool cmp(Node x,Node y) {return (x.x == y.x? x.w > y.w:x.x > y.x);}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		memset(cnt,0,sizeof(cnt));
		memset(ls,0,sizeof(ls));
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			int mx = max({x,y,z}),mn = min({x,y,z}),zz = x + y + z - mx - mn;
			a[i * 3 - 2] = (Node){i,x - zz,x,0};
			a[i * 3 - 1] = (Node){i,y - zz,y,1};
			a[i * 3] = (Node){i,z - zz,z,2};
		}
		sort(a + 1,a + (3 * n) + 1,cmp);
		for (int i = 1; i <= 3 * n; i++)
		{
			if (cnt[a[i].b] >= n / 2 || ls[a[i].id]) continue;
			ans += a[i].w; ls[a[i].id] = 1; cnt[a[i].b]++;
//			cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
