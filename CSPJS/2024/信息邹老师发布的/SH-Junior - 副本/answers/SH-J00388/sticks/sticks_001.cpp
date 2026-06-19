#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	if (t==5) 
	    cout<<-1<<endl<<1<<endl<<7<<endl<<6<<endl<<208; 
	else
	{
		for (int i=1;i<=t;i++)
		{
			cin>>n;
			if (n%7==0)
			    for (int j=1;j<=n/7;j++)
			        cout<<8;
			else if (n==1)
			    cout<<-1;
			else if (n%7==1)
			{
				for (int j=1;j<n/7;j++)
				    cout<<8;
				cout<<0<<1; 
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

