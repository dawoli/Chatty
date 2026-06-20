// Problem URL: https://www.luogu.com.cn/problem/T764683?contestId=318072
// Finish Time: 2026/6/20 16:51:30 WA 15pts
// Finish Time: 2026/6/20 16:40:19 WA 5pts
// Start Time: 2026/6/20 16:23:42

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1000006;
int n,q,half,B1,B2;
int k[MAXN],b[MAXN],p[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	half=n/2;
	for(int i=1; i<=n; ++i)
	{
		cin>>k[i]>>b[i];
		if(i==1) B1=b[i];
		if(i==half+1) B2=b[i];
	}
	p[0]=0;
	for(int i=1; i<=n; ++i)
	{
		p[i]=p[i-1];
		if(i>1&&k[i]!=k[i-1]) p[i]++;
	}
	bool isA=true;
	for(int i=2; i<=n; ++i)
	{
		if(b[i]!=b[1])
		{
			isA=false;
			break;
		}
	}
	bool isB=false;
	if(!isA)
	{
		isB=true;
		for(int i=1; i<=half; ++i)
		{
			if(b[i]!=B1) { isB=false; break; }
		}
		if(isB)
		{
			for(int i=half+1; i<=n; ++i)
			{
				if(b[i]!=B2) 
				{ 
					isB=false; 
					break; 
				}
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(isA)
		{
			cout<<"Yes\n";
		}
		else if(isB)
		{
			if(r<=half)
			{
				cout<<"Yes\n";
			}
			else if(l>half)
			{
				cout<<"Yes\n";
			}
			else
			{
				if(B1==B2)
				{
					cout<<"Yes\n";
				}
				else
				{
					bool ls=(p[half]-p[l]==0);
					bool rs=(p[r]-p[half+1]==0);
					if(ls&&rs)
					{
						int k1=k[l];
						int k2=k[half+1];
						if(k1!=k2) cout<<"Yes\n";
						else cout<<"No\n";
					}
					else
					{
						cout<<"No\n";
					}
				}
			}
		}
		else
		{
			if(l==r)
			{
				cout<<"Yes\n";
				continue;
			}
			int k1=k[l],b1=b[l];
			int k2=k[l+1],b2=b[l+1];
			bool ok=true;
			if(k1==k2)
			{
				if(b1!=b2)
				{
					ok=false;
				}
				else
				{
					for(int i=l+2; i<=r; ++i)
					{
						if(k[i]!=k1||b[i]!=b1)
						{
							ok=false;
							break;
						}
					}
				}
			}
			else
			{
				ll dx=(ll)k2-k1;
				ll dy=(ll)b2-b1;
				for(int i=l+2; i<=r; ++i)
				{
					ll cross=(ll)(k[i]-k1)*dy-(ll)(b[i]-b1)*dx;
					if(cross!=0)
					{
						ok=false;
						break;
					}
				}
			}
			cout<<(ok?"Yes":"No")<<'\n';
		}
	}
	return 0;
}