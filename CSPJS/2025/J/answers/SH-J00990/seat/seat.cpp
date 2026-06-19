#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int s, id;
}a[110];

bool cmp(node x, node y)
{
	return (x.s > y.s);
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int num;
	int c = 1, r = 1;
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i].id == 1)
		{
			cout << c << ' ' << r << endl;
			break;
		}
		if(r == n && c % 2 == 1 || r == 1 && c % 2 == 0)
		{
			c += 1;
		}
		else if(c % 2 == 0)
		{
			r -= 1;
		}
		else if(c % 2 == 1)
		{
			r += 1; 
		}
	}
	return 0;
}
