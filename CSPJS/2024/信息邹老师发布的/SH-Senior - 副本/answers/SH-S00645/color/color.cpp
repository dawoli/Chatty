#include <bits/stdc++.h>
#define ISRED(index) ((A[index] >> 31) == 1)
#define SETRED(index) (A[index] |= (1 << 31))
#define CLRRED(index) (A[index] &= 0x7FFFFFFF)
#define GETNUM(index) (A[index] & 0x7FFFFFFF)
using namespace std;
int T;
int maxS = -1;
void calc(unsigned int *A, int n, int l)
{
	
	if(l > n)
	{
		int lastR = -1, lastB = -1, curS = 0;
		for(int i = 1; i <= n; i++)
		{
			if(ISRED(i))
			{
				if(lastR == -1)
				{
					lastR = i;
					continue;
				}
				if(GETNUM(i) == GETNUM(lastR))
				{
					curS += GETNUM(i);
				}
				lastR = i;
			}
			else
			{
				if(lastB == -1)
				{
					lastB == i;
					continue;
				}
				if(GETNUM(i) == GETNUM(lastB))
				{
					curS += GETNUM(i);
				}
				lastB = i;
			}
		}
		maxS = max(curS, maxS);
		return;
	}
	SETRED(l);
	calc(A, n, l + 1);
	CLRRED(l);
	calc(A, n, l + 1);
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		unsigned int n, A[100010];
		scanf("%d", &n);
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &A[j]);
		}
		A[0] = 0;
		calc(A, n, 1);
		printf("%d\n", maxS);
		maxS = -1;
	}
	return 0;
}
