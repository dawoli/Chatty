#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int vt[3][50005];
int cnt[3];
struct node
{
	int a;
	int b;
	int c;
};
bool cmp(node &x, node &y)
{
	int p[3] = {x.a, x.b, x.c};
	int q[3] = {y.a, y.b, y.c};
	sort(p, p + 3);
	sort(q, q + 3);
	return p[2] - p[1] > q[2] - q[1];
}
node sati[100005];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		scanf("%d", &n);
		memset(vt, 0, sizeof(vt));
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d %d", &sati[i].a, &sati[i].b, &sati[i].c);
		}
		cnt[0] = cnt[1] = cnt[2] = 0;
		sort(sati, sati + n, cmp);
//		for(int i = 0;i < n;i++)
//		{
//			cout << sati[i].a << " " << sati[i].b << " " << sati[i].c << endl;
//		}
		for(int i = 0;i < n;i++)
		{
			int fir, sec;
			int mx = max(sati[i].a, max(sati[i].b, sati[i].c)), mn = min(sati[i].a, min(sati[i].b, sati[i].c));
			if(sati[i].a == mx) fir = 0;
			if(sati[i].b == mx) fir = 1;
			if(sati[i].c == mx) fir = 2;
			if(cnt[fir] < n / 2) vt[fir][cnt[fir]++] = i;
			else
			{
				int temp = vt[fir][cnt[fir] - 1];
				if(fir == 0 && max(sati[temp].b, sati[temp].c) + sati[i].a > sati[temp].a + max(sati[i].b, sati[i].c))
				{
					vt[fir][cnt[fir] - 1] = i;
					if(sati[temp].b >= sati[temp].c)
					{
						vt[1][cnt[1]++] = temp;
					}
					else
					{
						vt[2][cnt[2]++] = temp;
					}
				}
				else
				{
					if(fir == 0)
					{
						if(sati[i].b >= sati[i].c)
						{
							vt[1][cnt[1]++] = i;
						}
						else
						{
							vt[2][cnt[2]++] = i;
						}
					}	
				}
				if(fir == 1 && max(sati[temp].a, sati[temp].c) + sati[i].b > sati[temp].b + max(sati[i].a, sati[i].c))
				{
					vt[fir][cnt[fir] - 1] = i;
					if(sati[temp].a >= sati[temp].c)
					{
						vt[0][cnt[0]++] = temp;
					}
					else
					{
						vt[2][cnt[2]++] = temp;
					}
				}
				else
				{
					if(fir == 1)
					{
						if(sati[i].a >= sati[i].c)
						{
							vt[0][cnt[0]++] = i;
						}
						else
						{
							vt[2][cnt[2]++] = i;
						}
					}	
				}
				if(fir == 2 && max(sati[temp].b, sati[temp].a) + sati[i].c > sati[temp].c + max(sati[i].b, sati[i].a))
				{
					vt[fir][cnt[fir] - 1] = i;
					if(sati[temp].b >= sati[temp].a)
					{
						vt[1][cnt[1]++] = temp;
					}
					else
					{
						vt[0][cnt[0]++] = temp;
					}
				}
				else
				{
					if(fir == 2)
					{
						if(sati[i].b >= sati[i].a)
						{
							vt[1][cnt[1]++] = i;
						}
						else
						{
							vt[0][cnt[0]++] = i;
						}
					}	
				}
			}
//			cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
		}
		int ans = 0;
		for(int i = 0;i < cnt[0];i++)
		{
			ans += sati[vt[0][i]].a;
//			cout << vt[0][i] << " ";
		}
//		cout << endl;
		for(int i = 0;i < cnt[1];i++)
		{
			ans += sati[vt[1][i]].b;
//			cout << vt[1][i] << " ";
		}
//		cout << endl;
		for(int i = 0;i < cnt[2];i++)
		{
			ans += sati[vt[2][i]].c;
//			cout << vt[2][i] << " ";
		}
//		cout << endl;
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
*/
