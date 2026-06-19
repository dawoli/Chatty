#include<bits/stdc++.h>
using namespace std;
int n, r[100100], ans, msl2[50];
bool msl[100100]; 

//int f(int idx)
//{
//	if(idx == n)
//		return 0;
//	int ans = 99999, a[50];
//	for(int i = 0; i < n; i++)
//	for(int i = 0; i < n; i++)
//	{
//		if(i == idx || msl2[i] <= 0)
//			continue;
//		msl2[i] -= r[idx];
//		if(msl2[i] <= 0)
//			int tmp = f(idx + 1);
//		else
//			int tmp = f(idx + 1) + 1;
//		ans = min(ans, tmp);
//	}
//}

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &r[i]);
		msl[i] = false;
	}
	if(n == 1)
	{
		printf("1\n");
		return 0;
	}
	sort(r, r + n);
	if(r[n - 1] <= 2)
	{
		ans = n;
		int t1 = 0, t2 = n - 1;
		for(int i = n - 1; i >= 0; i--)
		{
			if(msl[i])
				break;
			if(r[i] == 2)
			{
				msl[t1] = true;
				t1++, ans--;
			}
			else
			{
				if(r[t2] == 2)
					t2--;
				else
				{
					msl[t1] = true;
					t1++, ans--;
				}
			}
		}
		printf("%d\n", ans);
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				mh2[i][j] = r[j];
		}
	}
	
	return 0;
}
