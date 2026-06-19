#include <bits/stdc++.h>
using namespace std;

long long t,n,m,l,v0,cam[100005],cnt1,cnt2,pos,cnt3;

struct car666{
	int a;
	int v;
	int d;
	int max1=-1,min1=1e9;
}car[100005];

bool cmp(car666 x333,car666 y444)
{
	if(x333.max1 == -1) return 0;
	if(y444.max1 == -1) return 1;
	if(x333.max1 == y444.max1) return x333.min1 <= y444.min1;
	return x333.max1 <= y444.max1;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	for(int wawawa = 1; wawawa <= t; wawawa++)
	{
		for(int i = 1; i <= 100005; i++)
		{
			car[i].max1=-1;
			car[i].min1=1e9;
		}

		cnt1=0;cnt2=0;cnt3=0;pos=0;
		cin >> n >> m >> l >>v0;
		for(int i = 1; i <= n; i++)
		{
			cin >> car[i].d >> car[i].v >> car[i].a;
			
		}
		for(int i = 1; i <= m; i++)
		{
			cin >> cam[i];
		}


		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if((car[i].v*car[i].v+2*car[i].a*(cam[j] - car[i].d)) > v0*v0 && cam[j] >= car[i].d)
				{
					if(car[i].max1==-1)cnt1++;
					car[i].min1 = min(car[i].min1,j);
					car[i].max1 = max(car[i].max1,j);
				}
			}
		}

		sort(car+1,car+n+1,cmp);

		pos = car[1].min1;
		cnt3=1;

		while(cnt3 <= cnt1)
		{
			pos=car[cnt3].max1;
//			cout << car[cnt3].max1<<cnt3;
			cnt3++;
			while(car[cnt3].min1 <= pos)
			{
				cnt3++;
//				cout << car[cnt3].max1<<cnt3;
			}
			cnt2++;
		}

		cout << cnt1<< " "<<m-cnt2<<endl;
	}
}
