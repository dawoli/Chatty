#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n,a[N],b[N];
set<int> s;
void init()
{
	a['D'] = 0;
	a['C'] = 1;
	a['S'] = 2;
	a['H'] = 3;
	b['A'] = 1;
	for (int i = 2; i <= 9; ++i) b['0' + i] = i;
	b['T'] = 10;
	b['J'] = 11;
	b['Q'] = 12;
	b['K'] = 13;
	for (int k = 1; k <= 52; ++k) s.insert(k);
}
int work(char x, char y) {return a[x] * 13 + b[y];}
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	init();
	scanf("%d", &n);
	while (n--)
	{
		char x,y;
		scanf(" %c %c", &x, &y);
		s.erase(work(x, y));
	}
	printf("%d\n", s.size());
	return 0;
}