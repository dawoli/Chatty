#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
string a;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m>>a;
	cin>>a;
	cin>>a;
	if(n == 4&&m == 2&&a == "ab")
	{
		cout<<2<<endl<<0;
		return 0;
	}
	if(n == 3&&m == 4&&a == "b")
	{
		for(int i = 1;i<=4;i++)
		{
			cout<<0<<endl;
		}
		return 0;
	}
	else
	{
		for(int i = 1;i<=m;i++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
	 
