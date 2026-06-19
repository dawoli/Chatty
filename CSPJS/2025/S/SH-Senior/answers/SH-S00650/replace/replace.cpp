#include <bits/stdc++.h>
using namespace std;

int n,q,ans,a[200005],b[200005],c[200005],d[200005],e[200005];
string s[200005][2],t[200005][2];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		int h=0;
		while (s[i][0][h]!='b')
		{
			a[i]++;
			h++;
		}
		h=0;
		while(s[i][1][h]!='b')
		{
			b[i]++;
			h++;
		}
		c[i]=a[i]-b[i];
	}
	for (int i=1;i<=q;i++)
	{
		cin>>t[i][0]>>t[i][1];
		int h=0;
		while (t[i][0][h]!='b')
		{
			d[i]++;
			h++;
		}
		h=0;
		while(t[i][1][h]!='b')
		{
			e[i]++;
			h++;
		}
		for (int j=1;j<=n;j++)
		{
			
			if(d[i]-e[i]==c[j]&&d[i]>=a[j])
				ans++;
		}
		cout<<ans<<endl;
	}
}
