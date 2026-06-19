#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int T,n;
int lst[13]={8,-1,1,7,4,2,6,8,10,18,22,20,60};
int main()
{
//	std::syns_with_stdin(false);
	cin.tie(0);
	cout.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		if (n>12)
		{
			if (n%7+7<=12)
			{
				cout<<min((n%7==1?1000000000:lst[n%7]*10+8),lst[n%7+7]);
				for (int i=1;i<=(n+6)/7-2;i++)
				{
					cout<<8;
				}
				if (n%7==0)
				{
					cout<<8;
				}
			}
			else
			{
				cout<<lst[n%7];
				for (int i=1;i<=(n+6)/7-1;i++)
				{
					cout<<8;
				}
			}
		}
		else
		{
			cout<<lst[n];
		}
		cout<<endl;
	}
	return 0;
}
