#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("sticks.in","r",stdin);
	freopen ("sticks.out","w",stdout);
	int t;cin >>t;
	for (int i=0;i<t;++i)
	{
		int n,a,b,c=-1;
		cin >>n;a=n/7,b=n%7;
		if (n<=1)
		{
			cout <<-1<<endl;
			continue;
		}
		if (n>=8&&b==1)
		{
			cout <<10;a--;c=0;
		}
		if (n>=10&&b==3)
		{
			cout <<22;a--;c=0;
		}
		if (n>=18&&b==4)
		{
			cout <<20;a--;c=0;
		}
		if (b==2&&c==-1) cout <<1;
		if (b==3&&c==-1) cout <<7;
		if (b==4&&c==-1) cout <<4;
		if (b==5&&c==-1) cout <<2;
		if (b==6&&c==-1) cout <<6;
		for (int j=0;j<a;++j) cout <<8;
		cout <<endl;
	}
	return 0;
}
