#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
set<string> s;

signed main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		s.insert(str);
	}
	cout<<52-s.size();
	return 0;
}

