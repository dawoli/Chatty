#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int NUM[] = {0, 1, 2, 4, 6, 7, 8};
const int NEED[] = {6, 2, 5, 4, 6, 3, 7};
struct node
{
	int a[10];
	string getnum()
	{
		string s = "";
		int start = 1;
		while (a[start] == 0 && start <= 9) start++;
		for (int i = 1; i <= a[start]; i++) s += char(start + '0');
		for (int i = 0; i <= 9; i++)
		{
			if (i == start) continue;
			for (int j = 1; j <= a[i]; j++) s += char(i + '0');
		}
		return s;
	}
} f[100005];
bool operator<(node x, node y)
{
	if (y.a[0] >= 0x3f3f3f3f) return 1;
	if (x.a[0] >= 0x3f3f3f3f) return 0;
	if (x.a[1] == 0 && x.a[2] == 0 && x.a[4] == 0 && x.a[6] == 0 && x.a[7] == 0 && x.a[8] == 0) x.a[0]--, x.a[6]++;
	if (y.a[1] == 0 && y.a[2] == 0 && y.a[4] == 0 && y.a[6] == 0 && y.a[7] == 0 && y.a[8] == 0) y.a[0]--, y.a[6]++;
	long long si1 = 0, si2 = 0;
	for (int i = 0; i <= 6; i++)
	{
		si1 += x.a[ NUM[ i ] ];
	    si2 += y.a[ NUM[ i ] ];
	}
	if (si1 != si2) return si1 < si2;
	int startx = 1, starty = 1;
	while (x.a[startx] == 0) startx++;
	while (y.a[starty] == 0) starty++;
	if (startx != starty) return startx < starty;
	if (x.a[startx] != y.a[starty]) return x.a[startx] > y.a[starty];
	for (int i = 0; i <= 9; i++)
	{
		if (i == startx) continue;
		if ( x.a[i] != y.a[i] ) return x.a[i] < y.a[i];
	}
	return 0;
}
void func()
{
	int n;
	cin >> n;
	if (n % 7 == 0)
	{
		for (int i = 1; i <= n / 7; i++)
		{
			cout << "8";
		}
		cout << "\n";
		return ;
	}
	if (n == 1)
	{
		cout << "-1\n";
		return ;
	}
	memset(f, 63, sizeof f);
	for (int i = 0; i <= 9; i++) f[0].a[i] = 0;
	for (int i = 0; i <= 6; i++)
	{
		for (int j = NEED[i]; j <= n; j++)
		{
			node x = f[j - NEED[i]];
			x.a[NUM[i]]++;
			if (x < f[j]) f[j] = x; 
		}
	}
	if (f[n].a[0] >= 0x3f3f3f3f) 
	{
		cout << "-1\n";
		return ;
	}
	else
	{
		node x = f[n];
		x.a[0] += x.a[6];
		x.a[6] = 0;
		if (x.a[1] == 0 && x.a[2] == 0 && x.a[4] == 0 && x.a[6] == 0 && x.a[7] == 0 && x.a[8] == 0) x.a[0]--, x.a[6]++;
		cout << x.getnum();
		cout << "\n";
	}
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) func();
	return 0;
}
