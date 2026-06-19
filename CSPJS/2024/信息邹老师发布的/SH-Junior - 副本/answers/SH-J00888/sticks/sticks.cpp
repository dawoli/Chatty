#include <bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		if (n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		int j=1;
		while (1)
		{
			int b=j,s=0;
			while (b>0)
			{
				int c=b%10;
				s+=a[c];
				b/=10;
			}
			if (s==n)
			{
				cout<<j<<endl;
				break;
			}
			j++;
		}
	}
	return 0;
}
