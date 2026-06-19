#include <bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string x,y;
};
const int N =2e5 + 7;
node a[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int t = 1;t <= n;t++)
	{
		cin >> a[t].x >> a[t].y;
		//cout << a[t].x << endl;
	}
	for(int t = 1;t <= q;t++)
	{	
		long long ans = 0;
		string u,v;
		cin >> u >> v;
		int sb = u.size();
		int l = -1,r = -1;
		for(int i = 0;i < sb;i++)
		{
			if(u[i] != v[i])
			{
				if(l == -1) l = i;
				r = max(r,i);
			}
		}
		for(int i = 1;i <= n;i++)
		{
			//cout << a[i].x << " ! " << a[i].y << endl;
			if(u.find(a[i].x) != string::npos && v.find(a[i].y) != string :: npos && u.find(a[i].x) == v.find(a[i].y))
			{
				int pos = u.find(a[i].x);
				if(pos <= l && pos + a[i].x.size() - 1 >= r) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
