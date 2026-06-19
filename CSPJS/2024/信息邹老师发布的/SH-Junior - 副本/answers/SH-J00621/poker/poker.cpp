#include<bits/stdc++.h>
using namespace std;

int t;
set<string> s;
string a;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>a;
		s.insert(a);
	}
	cout<<52-s.size()<<endl;
	return 0;
 } 
