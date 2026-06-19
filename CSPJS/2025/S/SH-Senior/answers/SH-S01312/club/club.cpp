#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, F[100005], a, b, c, d, e, f, ss;
struct K
{
	int S[4];
} A[100005];
bool T(K l, K r)
{
	int a = l.S[1], b = l.S[2], c = l.S[3], 
		d = r.S[1], e = r.S[2], f = r.S[3];
	if (a < b) swap(a, b);
	if (b < c) swap(b, c);
	if (a < b) swap(a, b);
	if (d < e) swap(d, e);
	if (e < f) swap(e, f);
	if (d < e) swap(d, e);
	if (a != d) return a > d;
	if (b != e) return b > e;
	return c > f;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &A[i].S[1], &A[i].S[2], &A[i].S[3]);
		sort(A + 1, A + 1 + n, T);
		memset(F, 0, sizeof (F));
		ss = 0;
		for (int i = 1; i <= n; i++)
		{
			int q1 = max_element(A[i].S + 1, A[i].S + 4) - A[i].S, 
				q3 = min_element(A[i].S + 1, A[i].S + 4) - A[i].S,
				q2 = 6 - q1 - q3;
			if (F[q1] < n / 2)
			{
				F[q1]++;
				ss += A[i].S[q1];
			}
			else if (F[q2] < n / 2)
			{
				F[q2]++;
				ss += A[i].S[q2];
			}
			else
			{
				F[q3]++;
				ss += A[i].S[q3];
			}
		}
		printf("%d\n", ss);
	}
	return 0;
}
