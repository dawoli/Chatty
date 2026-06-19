#include<bits/stdc++.h>
using namespace std;
int n;
string str;
set<string> s;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	while(n--)
	{
		cin>>str;
		s.insert(str);
	}
	cout<<52 - s.size();
	return 0;
}
