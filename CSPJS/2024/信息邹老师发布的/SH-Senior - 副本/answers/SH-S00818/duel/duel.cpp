#include <bits/stdc++.h>
using namespace std;
int read()
{
	int p = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9')	p = c == '-' ? -1 : 1,c = getchar(); 
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
	return p * x;
}
void _write(int x)
{
	if(x > 9)	_write(x / 10);
	putchar(x % 10 | 48);
}
void write(int x)
{
	if(x < 0)
		putchar('-');
	write(abs(x));
}
void writeln(int x)
{
	write(x);
	puts("");
}
/*

1 2 3 1 2

1 1 2 2 3
2->1
2->1


(1,2)
(2,2)
(3,1)
2 2 1
2 1
1
cnt = 0
for i in range(n - 1,0):
	sum += v[i + 1].second
	sum -=

136 136 136 136 136 136 136 136 2417 2417

*/
const int N = 1e5 + 10;
int n,r[N],cnt[N];
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> r[i],cnt[r[i]]++;
	vector<int> v;
	for(int i = 1;i <= 1e5;i++)
		if(cnt[i] > 0)
			v.push_back(cnt[i]);
	int ans = 0,sum = 0;
	for(int i = 0;i < v.size() - 1;i++)
	{
		sum += v[i];
		int t = min(v[i + 1],sum);
		sum -= t;
		ans += t;
	}
	cout << n - ans << endl;
	return 0;
}

