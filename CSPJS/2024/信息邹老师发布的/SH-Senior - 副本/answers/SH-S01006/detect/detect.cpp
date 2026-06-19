#include <bits/stdc++.h>
using namespace std;
int ps[100005],qs[100005],ds[100005];
int main()
{
	freopen("detect3.in","r",stdin);
	int t;
	cin>>t;
	while (t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for (int i=1;i<=a;i++)
		{
			int p,q,r;
			cin>>p>>q>>r;
			ps[i]=q;
			qs[i]=p;
		}
		for (int i=1;i<=b;i++)
		{
			int q;
			cin>>q;
			ds[i]=q;
		}
		int cnt=0,minn=b;
		for (int i=1;i<=a;i++)
		{
			for (int j=1;j<=b;j++)
			{
				if (qs[i]<=ds[j] && ps[i]>d)	cnt++;
				if (qs[i]>ds[j] && ps[i]<=d)	minn=min(minn,b-j);
			}
		}
		cout<<cnt<<endl;
		cout<<minn<<endl;
	}
	return 0;
}

