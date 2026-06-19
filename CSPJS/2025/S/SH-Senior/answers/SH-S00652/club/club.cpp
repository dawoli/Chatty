#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][10],s[N],cnt[10];
struct node{
	int x,id;
}f[N];
bool cmp(node x,node y)
{
	if(a[x.id][x.x] == a[y.id][y.x])
		return a[x.id][s[x.id]] < a[y.id][s[y.id]];
	else
		return a[x.id][x.x] > a[y.id][y.x];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cnt[1] = cnt[2] = cnt[3] = 0;
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
				if(a[i][f[i].x] < a[i][j])
					s[i] = f[i].x,f[i].x = j,f[i].id = i;
				else if(a[i][s[i]] < a[i][j])
					s[i] = j;
			}
		}
		sort(f + 1,f + n + 1,cmp);
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
//			cout << f[i].id << " " << f[i].x << " " << s[f[i].id] << "\n";
			if(cnt[f[i].x] < n / 2)
				ans += a[f[i].id][f[i].x],cnt[f[i].x]++;
			else
				ans += a[f[i].id][s[f[i].id]],cnt[s[f[i].id]];
//			cout << ans << " ";
		}
		cout << ans << "\n";
	}
	return 0;
 } 
