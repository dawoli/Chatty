# include <bits/stdc++.h>
using namespace std;
int sum[50]={0};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		sum[i-1]=t/7;
	}
	for(int i=0;i<n;i++)
	{
		for(int k=1;k<=sum[i];k++)
		{
			cout<<8;
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
