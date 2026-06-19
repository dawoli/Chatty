#include<bits/stdc++.h>
using namespace std;
struct node
{
	int st,ed;
	bool operator<(node r)
	{
		return ed<r.ed;
	}
}a[500010];
int t[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	for (int i=1;i<=n;i++)
	{
		int sum=0;
		for (int j=i;j<=n;j++)
		{
			sum^=t[j];
			if (sum==k)
			{
				a[j].ed=j;
				a[j].st=i;
			}
		}
	}
	a[0].ed=0;
	int time=0,cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (time<a[i].st)
		{
			time=a[i].ed;
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
