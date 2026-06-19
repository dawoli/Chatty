#include <bits/stdc++.h>
using namespace std;
map<string,bool> ma;
string s[20]={"","A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		ma[s]=true;
	}
	int cnt=0;
	for (int i=1;i<=13;i++)
	{
		if (!ma["D"+s[i]])	cnt++;
		if (!ma["C"+s[i]])	cnt++;
		if (!ma["H"+s[i]])	cnt++;
		if (!ma["S"+s[i]])	cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

