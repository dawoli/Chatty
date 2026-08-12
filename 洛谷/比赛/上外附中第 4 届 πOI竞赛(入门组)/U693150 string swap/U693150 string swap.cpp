#include<bits/stdc++.h>
using namespace std;
int n,l,r;
string s;
int a[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>l>>r;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	if(l==r&&l==1)
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			cout<<a[i];
		return 0;
	}
	for(int k=n;k>=1;k--)
	{
		for(int i=1;i<=k;i++)
		{
			int mn=i;
			for(int j=i+l;j<=i+r&&j<=n;j++)
			{
				if(a[mn]>a[j])mn=j;
			}
			swap(a[i],a[mn]);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i];
} 