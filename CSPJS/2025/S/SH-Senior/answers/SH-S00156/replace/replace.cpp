#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
unordered_map<ll,ll> num;
namespace A
{
	void solve()
	{
		while(n--)
		{
			string s,t;
			cin>>s>>t;
			ll s_pos=s.find('b'),t_pos=t.find('b');
			num[t_pos-s_pos]++;
		}
		while(q--)
		{
			string s,t;
			cin>>s>>t;
			ll s_pos=s.find('b'),t_pos=t.find('b');
			cout<<num[t_pos-s_pos]<<'\n';
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	A::solve();
	return 0;
}
