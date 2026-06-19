#include<bits/stdc++.h>
using namespace std;

int n, m, k, x0, y0, d0;
bool a[1010][1010], b[1010][1010];
void doit(int x, int y, int d, int now)
{
	b[x][y] = true;
	if(now == 0) return;
	if(d == 0)
	{
	    if(a[x][y + 1] && y < m)
	        doit(x, y + 1, d, now - 1);
	    else doit(x, y, 1, now - 1);
    }
    if(d == 1)
	{
	    if(a[x + 1][y] && x < n)
	        doit(x + 1, y, d, now - 1);
	    else doit(x, y, 2, now - 1);
    }
    if(d == 2)
	{
	    if(a[x][y - 1] && y > 1)
	        doit(x, y - 1, d, now - 1);
	    else doit(x, y, 3, now - 1);
    }
    if(d == 3)
	{
	    if(a[x - 1][y] && x > 1)
	        doit(x - 1, y, d, now - 1);
	    else doit(x, y, 0, now - 1);
    }
}
int main()
{
	int T;
	vector<int> ans;
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) 
	{
		int sum = 0;
	    memset(a, true, sizeof(a));
	    memset(b, false, sizeof(b));
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		for(int i = 1;i <= n;i++)
		{
			string s;
			cin >> s;
		    for(int j = 0;j < m;j++)
		        if(s[j] == 'x')
		            a[i][j + 1] = false;
		}
		doit(x0, y0, d0 ,k);
		for(int i = 1;i <= n;i++)
		    for(int j = 1;j <= m;j++)
		        if(b[i][j])
		            sum++;
		ans.push_back(sum);
	}
	for(int i = 0;i < ans.size();i++)
	    cout << ans[i] << '\n';
	    
	return 0;
}
