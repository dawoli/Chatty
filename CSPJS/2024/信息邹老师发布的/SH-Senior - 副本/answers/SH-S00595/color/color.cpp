#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int t,n;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n],c=0;
		bool t[1006];
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			int j=i+1;
			while(a[j]!=a[i]&&j<=n) j++;
			if(j>n) continue;
			else t[a[i]]=j;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<t[a[i]];j++)
			{
				if(t[a[j]])
				{
					if(a[j]>a[i])
					{
						t[a[i]]=0;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(t[a[i]]) c+=a[i];
		cout<<c/2<<'\n';
	}
	return 0;
}
