#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10e5+2;
int n,m,L,V,T,tot,res,tmp;
bool flag;
struct car{int d; int v; int a;} cars[N];
bool p[N]={0};
int ct[N];
ll calc(car c, int dis) {return c.v*c.v+2*c.a*dis;}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdin);
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		scanf("%d %d %d %d", &n, &m, &L, &V);
		memset(ct, N, 0);
		memset(p, N, 0);
		tot = 0; res = 0;
		for (int j=1; j<=n; j++)
			scanf("%d %d %d", &cars[j].d, &cars[j].v, &cars[j].a);
		for (int j=1; j<=m; j++) {
			scanf("%d", &tmp);
			p[tmp] = true;
		}
		for (int c=1; c<=n; c++) {
			flag = true;
			for (int dis=0; dis<=L; dis++) // the distance
				if (calc(cars[c], dis) > (ll)V*V) // over limit
				{
					if (p[cars[c].d+dis]) {
						ct[cars[c].d+dis]++;
						if (flag) {res++; flag=false;}
					}
				}
		}
		for (int dis=1; dis<=L; dis++)
				if (ct[dis] > ct[dis-1]) tot++;
		printf("%d %d\n", tot, res);
	}
	return 0;
}
