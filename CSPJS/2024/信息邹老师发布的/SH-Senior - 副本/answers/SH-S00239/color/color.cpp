#include<bits/stdc++.h>
using namespace std;
int T;
int a[200000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long res=0;
		sort(a,a+n-1,cmp);
		int x=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[x])
			{
				res+=a[i]
			}
			else
			{
				x=i;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
