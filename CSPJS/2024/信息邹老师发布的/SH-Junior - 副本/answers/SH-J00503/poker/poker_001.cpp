#include<bits/stdc++.h>

using namespace std;

int ans=0,n,a[53][2];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string x;
		cin>>x;
		bool b=0;

		if(i==1)
		{
			ans++;
		}
		else if(i!=1)
		{
			for(int j=1;j<=i;j++)
			{
				if(a[j][0]==int(x[0])&&a[j][1]==int(x[1]))
				{
					b=1;
				}
			}
			if(b==0)
			{
				ans++;
			}			
		}
		a[i][0]=int(x[0]);
		a[i][1]=int(x[1]);
	}
	cout<<52-ans<<endl;
	return 0;
}
