#include <bits/stdc++.h>
using namespace std;
#define int long long
int r[100010],q[100010],hd = 1,tl = 0;

template <typename T> void read(T &t)
{
	int f = 1;
	char c = getchar();
	t = 0;
	while(c < '0' || c > '9')
	{
		if(c == '-')
			f = -1;
		c = getchar(); 
	}
	while(c >= '0' && c <= '9')
	{
		t = (t << 3) + (t << 1) + (c ^ 48);
		c = getchar(); 
	}
	t *= f;
}

signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	read(n);
	for(int i = 1; i <= n; i++)
		read(r[i]);
	sort(r + 1,r + n + 1);
	int cnt = n;
	for(int i = 1; i <= n; i++)
	{
		if(hd <= tl && r[q[hd]] < r[i])
			hd++,cnt--;
		q[++tl] = i;
	}
	cout << cnt << '\n';
    return 0;
}
