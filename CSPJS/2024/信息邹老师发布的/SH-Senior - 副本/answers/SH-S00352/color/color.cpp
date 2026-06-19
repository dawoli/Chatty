#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
const int M = 1e6+2;
int f[N][2], T, n, A[M], ld, anss[12];
bool flag;

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%d", &n);
		for (int j=1; j<=n; j++) scanf("%d", A+j);
		ld = 0;
		f[1][1]=0; f[1][0]=0; f[0][0]=0; f[0][1] = 0;
		int rec=0;
		for (int i=1; i<=n; i++)
		{
			f[i][0] = max(f[i-1][0]+(A[i]==A[i-2]?A[i]:0),  f[i-1][1]+(A[i]==A[j]?A[i]:0));
			f[i][1] = max(f[i-1][0]+(A[i]==A[i-1]?A[i]:0),  f[i-1][1]+(A[i]==A[i-1]?A[i]:0));
			if (f[i-1][0]+(A[i]==A[i-1]?A[i]:0) > f[i-1][1]+(A[i]==A[i-1]?A[i]:0)) ld=i-2;
		}
		anss[t] = max(f[n][0], f[n][1]);
	}
	for (int t=1; t<=T; t++)
		printf("%d\n", anss[t]);
	return 0; 
}
