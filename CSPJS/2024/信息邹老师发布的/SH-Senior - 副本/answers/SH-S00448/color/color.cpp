#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[100005]={};
		bool f[100005]={};
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<i;j++)
			{
				if(a[i]==a[j]&&f[j]!=1)
				{
					cnt+=a[i];
					f[i]=1;
					f[j]=1;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
