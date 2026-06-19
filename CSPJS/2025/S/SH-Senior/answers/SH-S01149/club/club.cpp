#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a[5],b;
};
int t,n,s[5],maxs;
long long ans;
node l[100005];
int f(node x)
{
	if (x.a[1]>=x.a[2] && x.a[1]>=x.a[3]) return 1;
	if (x.a[2]>=x.a[1] && x.a[2]>=x.a[3]) return 2;
	return 3;
}
int _f(node x)
{
	if (x.a[1]>=x.a[2] && x.a[2]>=x.a[3] || x.a[3]>=x.a[2] && x.a[2]>=x.a[1]) return 2;
	if (x.a[2]>=x.a[1] && x.a[1]>=x.a[3] || x.a[3]>=x.a[1] && x.a[1]>=x.a[2]) return 1;
	return 3;
}
void f1(int x)
{
	if (l[x].a[1]>=l[x].a[2] && l[x].a[1]>=l[x].a[3])
	{
		l[x].b=min(l[x].a[1]-l[x].a[2],l[x].a[1]-l[x].a[3]);
		return;
	}
	if (l[x].a[2]>=l[x].a[1] && l[x].a[2]>=l[x].a[3])
	{
		l[x].b=min(l[x].a[2]-l[x].a[1],l[x].a[2]-l[x].a[3]);
		return;
	}
	l[x].b=min(l[x].a[3]-l[x].a[1],l[x].a[3]-l[x].a[2]);
	return;
}
bool cmp(node x,node y)
{
	if (f(x) == maxs && f(y) == maxs) return x.b>y.b;
	if (f(x) != maxs) return f(y) != maxs;
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		ans=0;
		cin >> n;
		for (int j=1;j<=n;j++)
		{
			cin >> l[j].a[1] >> l[j].a[2] >> l[j].a[3];
			s[f(l[j])]++;
			f1(j);
		}
		if (s[1]>=s[2] && s[1]>=s[3]) maxs=1;
		else if (s[2]>=s[1] && s[2]>=s[3]) maxs=2;
		else maxs=3;
		sort(l+1,l+n+1,cmp);
		for (int j=1;j<=n;j++)
		{
			if (j>n/2 && f(l[j])==maxs)
			{
				ans+=l[j].a[f(l[j])]-l[j].b;
			}
			else
			{
				ans+=l[j].a[f(l[j])];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
