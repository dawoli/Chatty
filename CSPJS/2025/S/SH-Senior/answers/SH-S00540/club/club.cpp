#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int a1,a2,a3;
	int mo12,mo21,mo13,mo31,mo23,mo32;
};
bool cmp1(node a,node b)
{
	return min(a.mo12,a.mo13) > min(b.mo12,b.mo13);
}
bool cmp2(node a,node b)
{
	return min(a.mo21,a.mo23) > min(b.mo21,b.mo23);
}
bool cmp3(node a,node b)
{
	return min(a.mo31,a.mo32) > min(b.mo31,b.mo32);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i ++)
	{
		node a[100005] = {};
		node b[100005] = {};
		node c[100005] = {};
		int n;
		cin >> n;
		int b1= 0,b2 = 0,b3 = 0,w = 0;
		for (int j = 1; j <= n; j ++)
		{
			node t;
			cin >> t.a1 >> t.a2 >> t.a3;
			t.mo12 = t.a1 - t.a2;
			t.mo21 = t.a2 - t.a1;
			t.mo13 = t.a1 - t.a3;
			t.mo31 = t.a3 - t.a1;
			t.mo23 = t.a2 - t.a3;
			t.mo32 = t.a3 - t.a2;
			if (t.a1 >= t.a2 && t.a1 >= t.a3)
			{
				a[++b1] = t;
				w += t.a1;
			}
			else if (t.a2 >= t.a1 && t.a2 >= t.a3)
			{
				b[++b2] = t;
				w += t.a2;
			}
			else if (t.a3 >= t.a1 && t.a3 >= t.a2)
			{
				c[++b3] = t;
				w += t.a3;
			}
		}
		if (b1 > n / 2)
		{
			sort (a + 1,a + b1 + 1,cmp1);
			while (b1 > n / 2)
			{
				w -= min(a[b1].mo12,a[b1].mo13);
				b1 --;
			}
		}
		else if (b2 > n / 2)
		{
			sort (b + 1,b + b2 + 1,cmp2);
			while (b2 > n / 2)
			{
				w -= min(b[b2].mo21,b[b2].mo23);
				b2 --;
			}
		}
		else if (b3 > n / 2)
		{
			sort (c + 1,c + b3 + 1,cmp3);
			while (b3 > n / 2)
			{
				w -= min(c[b3].mo31,c[b3].mo32);
				b3 --;
			}
		}
		cout << w << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
