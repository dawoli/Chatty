#include <bits/stdc++.h>
using namespace std;
int n;
char a,b;
set<pair<char,char>> s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a>>b,s.insert(make_pair(a,b));
	cout<<52-s.size();
	return 0; 
} 
