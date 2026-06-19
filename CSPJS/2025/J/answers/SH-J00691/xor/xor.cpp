#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e5+5;

set<ll> s;
ll n,k,ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	s.insert(0);
	for(int i=1,x,y=0;i<=n;i++)
	{
		cin>>x;
		y^=x;
//		cout<<(y^k)<<endl;
		if(s.find(y^k)!=s.end())
		{
			y=0;
			s.clear();
			ans++;
		}
		s.insert(y);
	}
	cout<<ans<<endl;
	return 0;
}
