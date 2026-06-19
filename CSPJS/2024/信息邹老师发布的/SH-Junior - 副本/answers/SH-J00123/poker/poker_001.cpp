#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	LL n=0;
	cin>>n;
	set<string>s;
	while(n--)
	{
		string tmp;
		cin>>tmp;
		s.insert(tmp);
	}
	cout<<52-s.size();
	return 0;
}
