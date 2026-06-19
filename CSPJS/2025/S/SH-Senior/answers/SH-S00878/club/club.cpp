#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5,MOD=0;
int t,n;
long long ans;
struct Member
{
	pair<int,int> d[4];
}a[MAXN+5];
bool cmp(Member n1,Member n2)
{
	return abs(n1.d[1].first-n1.d[2].first)>abs(n2.d[1].first-n2.d[2].first);
}
void dfs(int pos,int t1,int t2,int t3,long long sum)
{
	if (pos==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if (t1<n/2) dfs(pos+1,t1+1,t2,t3,sum+a[pos].d[1].first);
	if (t2<n/2) dfs(pos+1,t1,t2+1,t3,sum+a[pos].d[2].first);
	if (t3<n/2) dfs(pos+1,t1,t2,t3+1,sum+a[pos].d[3].first);
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int main()
{
	init();
	cin>>t;
	while (t--)
	{
		cin>>n;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].d[1].first>>a[i].d[2].first>>a[i].d[3].first;
			a[i].d[1].second=1;
			a[i].d[2].second=2;
			a[i].d[3].second=3;
			if (a[i].d[1]<a[i].d[2]) swap(a[i].d[1],a[i].d[2]);
			if (a[i].d[2]<a[i].d[3]) swap(a[i].d[2],a[i].d[3]);
			if (a[i].d[1]<a[i].d[2]) swap(a[i].d[1],a[i].d[2]);
		}
		sort(a+1,a+1+n,cmp);
		int t[4]={};
		for (int i=1;i<=n;i++)
		{
			if (t[a[i].d[1].second]<n/2)
			{
				t[a[i].d[1].second]++;
				ans+=a[i].d[1].first;
			}
			else
			{
				t[a[i].d[2].second]++;
				ans+=a[i].d[2].first;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
