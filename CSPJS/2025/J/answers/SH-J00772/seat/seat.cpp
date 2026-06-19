#include <bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	bool f;
}a[110];
bool cmp(node xx, node yy)
{
	return xx.num > yy.num;
}
int n, m;
int hang, lie;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++)
	{
		cin >> a[i].num;
		if(i == 1)
			a[i].f = 1;
		else
			a[i].f = 0;
	}
	
	sort(a + 1, a + 1 + n * m, cmp);
	
	for(int i = 1;i <= n * m;i ++)
	{
		lie = i / n;
		if(i % n)
			lie ++;
		hang = i % n;
		if(hang == 0)
			hang = n;
						
		if(!(lie % 2))
			hang = n - hang + 1;
		if(a[i].f)
		{
			cout << lie << " " << hang << endl;
			return 0;
		}
	}
	return 0;
}
