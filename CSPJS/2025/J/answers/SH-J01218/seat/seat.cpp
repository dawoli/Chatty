#include <bits/stdc++.h>
#define N 105
using namespace std;
typedef long long ll;

int n,m,me;
int all,a[N]; 
bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	all = n * m;
	for (int i = 1;i <= all;i++)
		cin >> a[i];
	me = a[1];
	sort(a + 1,a + all + 1,cmp);
	int id;
	for (id = 1;id <= all;id++)
		if (a[id] == me) break;
//	for (int i = 1;i <= all;i++)
//		cout << a[i] << " ";
	int c,r;
	c = id / n;
	if (id % n != 0) c++;
	if (c % 2 == 0) r = (n - (id - (c - 1) * n) + 1);
	else r = (id - (c - 1) * n);
	cout << c << " " << r;
	return 0;
}
