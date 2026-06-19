#include <iostream>
#include <cstdio>
#include <algorithm>
struct g
{
	int z;
	bool f=false,h=true;
}r[100005];
int n;
bool cmp(g a, g b)
{
	if(a.h!=b.h)
	{
		return a.h > b.h;
	}
	else if(a.z!=b.z)
	{
		return a.z < b.z;
	}
	else
	{
		return a.f < b.f;
	}
}
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> r[i].z;
	}
	sort(r+1,r+1+n,cmp);
	int x=n,s=n;
	while(x)
	{
		for(int i=2; i<=s; i++)
		{
			if(r[i].f == false&&r[i].h)
			{
				for(int j=i; j>=1; j--)
				{
					if(r[j].z<r[i].z&&r[j].h)
					{
						r[i].f=true;
						r[j].h=false;
						if(r[j].f)x--;
						else x-=2;
						s--;
						goto qaq;
					}
				}
			}
		}
		break;
		qaq:;
		sort(r+1,r+n+1,cmp);
	}
	cout <<s << endl;
	return 0;
}
