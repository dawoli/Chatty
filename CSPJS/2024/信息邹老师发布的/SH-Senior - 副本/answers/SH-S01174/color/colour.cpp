#include<bits/stdc++.h>
using namespace std;
long long a[200005],c;
int main()
{
	freopen("colour.in","r",stdin);
	freopen("colour.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{	
		c=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[n];
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((a[i]==a[j])&&(i!=j))
				{
					c+=a[i];
					a[i]=0;
					a[j]=0;
				}
			}
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
