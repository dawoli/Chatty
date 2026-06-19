# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;

int n, m, c, r;
struct Stu
{
	int score;
	int id;
	int p;
};
Stu a[105];

bool cmp(Stu a, Stu b)
{
	return a.score > b.score;
}

bool cmp2(Stu a, Stu b)
{
	return a.id < b.id;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
	{
		cin >> a[i].score;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++)
	{
		a[i].p = i;
	}
	sort(a + 1, a + n * m + 1, cmp2);
	int k = a[1].p;
	if (k % n == 0)
	{
		c = k / n;
		if (c % 2 != 0)
		{
			cout << c << " " << m;
			return 0;
		}
		else
		{
			cout << c << " " << 2;
			return 0;
		}
	}
	else c = k / n + 1;
	if (c % 2 != 0)
	{
		r = k - int(k/n) * n;
	}
	else
	{
		r = n - (k - int(k/n) * n);
	}
	cout << c << " " << r;
	return 0;
} 
