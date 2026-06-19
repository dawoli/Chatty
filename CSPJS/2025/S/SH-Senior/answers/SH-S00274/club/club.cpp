#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
struct stu
{
	int x,y,z,f,d;
};
stu a[N];
int t;
bool cmp(stu p,stu q)
{
	if(p.f!=q.f) return abs(t-p.f)<abs(t-q.f);
	else return p.d<q.d;
}
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		t=0;
		int n,c1=0,c2=0,c3=0,s=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=max(a[i].y,a[i].z))
			{
				a[i].f=1;
				a[i].d=a[i].x-max(a[i].y,a[i].z);
				c1++;
				s+=a[i].x;
			}
			else if(a[i].y>=max(a[i].x,a[i].z))
			{
				a[i].f=2;
				a[i].d=a[i].y-max(a[i].x,a[i].z);
				c2++;
				s+=a[i].y;
			}
			else
			{
				a[i].f=3;
				a[i].d=a[i].z-max(a[i].x,a[i].y);
				c3++;
				s+=a[i].z;
			}
		}
		if(c1>n/2) t=1;
		if(c2>n/2) t=2;
		if(c3>n/2) t=3;
		if(t==0) cout<<s<<'\n';
		else
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=max(max(c1,c2),c3)-n/2;i++) s-=a[i].d;
			cout<<s<<'\n';
		}
	}
	return 0;
}

