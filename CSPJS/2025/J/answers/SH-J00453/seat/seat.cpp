#include<bits/stdc++.h>
using namespace std;

struct ti
{
	int sl, id;
};

bool operator<(ti a, ti b)
{
	return a.sl < b.sl;
}

const int N = 105;
ti a[N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	int n, m;
	scanf("%d%d", &m, &n);
	int z = n * m;
	for(int i = 1; i <= z; i++) scanf("%d", &a[i].sl);
	for(int i = 1; i <= z; i++) a[i].id = i;
	sort(a + 1, a + z + 1);
	int tar;
	for(int i = 1; i <= z; i++)
	{
		if(a[i].id == 1)
		{
			tar = z - i;
			break;
		}
	}
	int col = tar / m + 1, row;
	if(col % 2 == 1) row = tar % m + 1;
	else row = m - tar % m;
	printf("%d %d", col, row);
 } 
