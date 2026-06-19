#include <bits/stdc++.h>
using namespace std;

//struct _
//{
//	int a1, a2, a3;
//	double b1, b2, b3;
//	bool vis;
//} a[210];
//int T;
//int p1[210], p2[210], p3[210];
//
//bool cmp1(int x, int y)
//{
//	double chax = a[x].b1-max(a[x].b2, a[x].b3);
//	double chay = a[y].b1-max(a[y].b2, a[y].b3);
//	return chax > chay;
//}
//
//bool cmp2(int x, int y)
//{
//	double chax = a[x].b2-max(a[x].b1, a[x].b3);
//	double chay = a[y].b2-max(a[y].b1, a[y].b3);
//	return chax > chay;
//}
//
//bool cmp3(int x, int y)
//{
//	double chax = a[x].b3-max(a[x].b1, a[x].b2);
//	double chay = a[y].b3-max(a[y].b1, a[y].b2);
//	return chax > chay;
//}
//
//int main()
//{
//	freopen("club4.in", "r", stdin);
//	freopen("club.out", "w", stdout);
//	scanf("%d", &T);
//	while (T--)
//	{
//		memset(p1, 0, sizeof(p1));
//		memset(p2, 0, sizeof(p2));
//		memset(p3, 0, sizeof(p3));
//		int n, cnt = 0;
//		scanf("%d", &n);
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
//			double sum = a[i].a1+a[i].a2+a[i].a3;
//			a[i].b1 = a[i].a1/sum;
//			a[i].b2 = a[i].a2/sum;
//			a[i].b3 = a[i].a3/sum;
////			printf("%d %d %d  %lf %lf %lf\n", a[i].a1, a[i].a2, a[i].a3, a[i].b1, a[i].b2, a[i].b3);
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			if (a[i].b1 >= a[i].b2 && a[i].b1 >= a[i].b3) p1[++p1[0]] = i;
//			else if (a[i].b2 >= a[i].b1 && a[i].b2 >= a[i].b3) p2[++p2[0]] = i;
//			else if (a[i].b3 >= a[i].b1 && a[i].b3 >= a[i].b2) p3[++p3[0]] = i;
//		}
//		if (p1[0] > n/2)
//		{
//			sort(p1+1, p1+p1[0]+1, cmp1);
//			while (p1[0] > n/2)
//			{
//				int x = p1[p1[0]];
//				if (a[x].b2 >= a[x].b3)
//				{
//					p2[++p2[0]] = x;
//					p1[p1[0]--] = 0;
//				}
//				else
//				{
//					p3[++p3[0]] = x;
//					p1[p1[0]--] = 0;
//				}
//			}
//		}
//		if (p2[0] > n/2)
//		{
//			sort(p2+1, p2+p2[0]+1, cmp2);
//			while (p2[0] > n/2)
//			{
//				int x = p2[p2[0]];
//				if (a[x].b1 >= a[x].b3)
//				{
//					p1[++p1[0]] = x;
//					p2[p2[0]--] = 0;
//				}
//				else
//				{
//					p3[++p3[0]] = x;
//					p2[p2[0]--] = 0;
//				}
//			}
//		}
//		if (p3[0] > n/2)
//		{
//			sort(p3+1, p3+p3[0]+1, cmp3);
//			while (p3[0] > n/2)
//			{
//				int x = p3[p3[0]];
//				if (a[x].b1 >= a[x].b2)
//				{
//					p1[++p1[0]] = x;
//					p3[p3[0]--] = 0;
//				}
//				else
//				{
//					p2[++p2[0]] = x;
//					p3[p3[0]--] = 0;
//				}
//			}
//		}
//		for (int i = 1; i <= p1[0]; i++) cnt += a[p1[i]].a1;
//		for (int i = 1; i <= p2[0]; i++) cnt += a[p2[i]].a2;
//		for (int i = 1; i <= p3[0]; i++) cnt += a[p3[i]].a3;
//		printf("%d\n", cnt);
//	}
//	return 0;
//}

int T, n;
struct _
{
	int a1, a2, a3;
} a[210];
vector <int> c1, c2, c3;
bool fa = 1;
int maxn = 0;

bool cmp(_ x, _ y)
{
	return x.a1 > y.a1;
}

void dfs(int dep)
{
	if (dep == n+1)
	{
		int sum = 0;
		for (int i = 0; i < c1.size(); i++) sum += a[c1[i]].a1;
		for (int i = 0; i < c2.size(); i++) sum += a[c2[i]].a2;
		for (int i = 0; i < c3.size(); i++) sum += a[c3[i]].a3;
		maxn = max(maxn, sum);
		return;
	}
	if (c1.size()+1 <= n/2)
	{
		c1.push_back(dep);
		dfs(dep+1);
		c1.pop_back();
	}
	if (c2.size()+1 <= n/2)
	{
		c2.push_back(dep);
		dfs(dep+1);
		c2.pop_back();
	}
	if (c3.size()+1 <= n/2)
	{
		c3.push_back(dep);
		dfs(dep+1);
		c3.pop_back();
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		maxn = 0;
		fa = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
			if (a[i].a2 != 0 || a[i].a3 != 0) fa = 0;
		}
		if (fa)
		{
			sort(a+1, a+n+1, cmp);
			int sum = 0;
			for (int i = 1; i <= n/2; i++) sum += a[i].a1;
			maxn = sum;
		}
		if (!fa) dfs(1);
		printf("%d\n", maxn);
	}
}
