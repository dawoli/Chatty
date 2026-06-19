#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+5;

ll t,n,a[N][5],aa,bb,cc,d,e,f,ans;
multiset<ll> s;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		aa=0;
		bb=0;
		cc=0;
		s.clear();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				aa++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				bb++;
			}
			else
			{
				cc++;
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(aa>n/2)
		{
			d=1;
		}
		else if(bb>n/2)
		{
			d=2;
		}
		else if(cc>n/2)
		{
			d=3;
		}
		else
		{
			cout<<ans<<endl;
			continue;
		}
		e=d%3+1;
		f=e%3+1;
//		cout<<d<<' '<<e<<' '<<f<<endl;
		ans=0;
		for(int i=1,x,y,z;i<=n;i++)
		{
			ans+=a[i][d];
			s.insert(a[i][d]-max(a[i][e],a[i][f]));
		}
		ll x=1;
		for(auto it:s)
		{
			if(x>n/2)
			{
				break;
			}
			ans-=it;
			x++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
