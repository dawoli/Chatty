#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
		cin >> a[i];
	int R = a[1];
	sort(a+1,a+n*m+1,cmp);
	int x = 1, y = 0;
	for (int i = 1;i <= n*m;i++)
	{
		if (x % 2 == 1)
			y++;
		else
			y--;
		if (y == n+1 || y == 0)
		{
			if (y == n+1) y = n;
			if (y == 0) y = 1; 
			x++; 
		}
		if (a[i] == R)
			cout << x << ' ' << y << endl;
	}
	return 0; 
} 
/*
3 4
1 12 2 3 4 5 6 7 8 9 10 11
*/
