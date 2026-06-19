#include <bits/stdc++.h>
using namespace std;
int a[90][90];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s;
	int n,c=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		int x=s[0],y=s[1];
		if (a[x][y]==0)
		{
			a[x][y]++;
			c++;
		}
	}
	cout<<52-c;
	
	return 0;
}
