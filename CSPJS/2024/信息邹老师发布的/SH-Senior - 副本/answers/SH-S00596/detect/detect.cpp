#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,L,V,p[100005];
struct node
{
	ll d,v,a;
} c[100005];
struct node2
{
	ll l,r;
} q[100005];
void input()
{
	cin>>n>>m>>L>>V;
	for(ll i = 1;i <= n;i++)
	{
		cin>>c[i].d>>c[i].v>>c[i].a; 
	}
	for(ll i = 1;i <= m;i++) cin>>p[i];
}
bool cmp(node x,node y)
{
	return x.d < y.d;
}
bool cmp2(node2 x,node2 y)
{
	return x.r < y.r;
}
bool Is_conditionA()
{
	for(ll i = 1;i <= n;i++)
	{
		if(c[i].a != 0) return 0;
	}
	return 1;
}
void solve1()
{
	ll cnt = 0;
	for(ll i = 1;i <= n;i++)
	{
		ll minn = 1e9,maxx = 0;
		for(ll j = 1;j <= m;j++)
		{
			if(p[j] < c[i].d) continue;
			double now = sqrt(c[i].v * c[i].v + 2 * c[i].a * (p[j] - c[i].d));
			if(now > V)
			{
				minn = min(minn,p[j]);
				maxx = max(maxx,p[j]);
			}
		}
		if(minn == 1e9) continue;
		if(maxx == 0) maxx = minn;
		cnt += 1;
//		cout<<minn<<" "<<maxx<<" "<<i<<" "<<c[i].d<<endl;
		q[cnt].l = minn;
		q[cnt].r = maxx;
	}
	sort(q + 1,q + cnt + 1,cmp2);
	ll now = 1e9,cnt2 = 0;
	for(ll i = 1;i <= cnt;i++)
	{
//		cout<<q[i].l<<" "<<q[i].r<<endl;
		if(q[i].l <= now && q[i].r >= now) continue;
		cnt2 += 1;
		now = q[i].r;
	}
	cout<<cnt<<" "<<m - cnt2<<endl;
}
void solve2()
{
	sort(p + 1,p + m + 1);
	sort(c + 1,c + n + 1,cmp);
//	cout<<1<<endl;
	ll cnt = 0,cur = 1;
	for(ll i = 1;i <= n;i++)
	{
		while(p[cur] < c[i].d && cur < m) cur += 1;
		if(c[i].d > p[m]) continue;
		if(c[i].v > V)
		{
			cnt += 1;
			q[cnt].l = p[cur];
			q[cnt].r = p[m];
		}
	}
	sort(q + 1,q + cnt + 1,cmp2);
	ll now = 1e9,cnt2 = 0;
	for(ll i = 1;i <= cnt;i++)
	{
//		cout<<1<<endl;
//		cout<<q[i].l<<" "<<q[i].r<<endl;
		if(q[i].l <= now && q[i].r >= now) continue;
		cnt2 += 1;
		now = q[i].r;
	}
	cout<<cnt<<" "<<m - cnt2<<endl;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		input();
//		cout<<n<<"    "<<m<<endl;
		if(n * m <= 1e8 * 2) solve1();
		else if(Is_conditionA()) solve2();
	}
	return 0;
}
