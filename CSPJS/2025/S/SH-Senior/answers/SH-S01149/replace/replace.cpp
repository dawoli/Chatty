#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string s1,s2;
	int l;
};
string t1,t2;
node a[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].s1 >> a[i].s2;
		a[i].l=a[i].s1.size();
	}
	for (int i=1;i<=q;i++)
	{
		int ans=0;
		cin >> t1 >> t2;
		if (t1.size()!=t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		int b,e=t1.size();
		for (int j=0;j<t1.size();j++)
		{
			if (t1[j]!=t2[j])
			{
				b=j;
				break;
			}
		}
		for (int k=t1.size()-1;k>=0;k--)
		{
			if (t1[k]!=t2[k])
			{
				e=k+1;
				break;
			}
		}
		for (int j=1;j<=n;j++)
		{
			if (a[j].l<e-b || a[j].l>t1.size()) break;
			for (int k=max(0,e-a[j].l);k<=b;k++)
			{
				bool flag=true;
				for (int p=0;p<a[j].l;p++)
				{
					if (a[j].s1[p] != t1[k+p])
					{
						flag=false;
						break;
					}
				}
				if (flag)
				{
					for (int p=0;p<a[j].l;p++)
					{
						if (a[j].s2[p] != t2[k+p])
						{
							flag=false;
							break;
						}
					}
					if (flag)
					{
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
