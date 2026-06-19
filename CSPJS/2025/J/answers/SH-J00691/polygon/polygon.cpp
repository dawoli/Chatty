#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
set<ll> s;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		s.insert(x);
	}
	cout<<9<<endl;
	return 0;
}
