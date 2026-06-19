#include<bits/stdc++.h>
using namespace std;
int amount[10]={6,2,5,5,4,5,6,3,7,6};
int ans[10];
int T,n,cnt=0;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while (T--)
	{
		memset(ans,0,sizeof(ans));
		cnt=0;
		cin>>n;
		if (n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		ans[8]+=n/7;
		cnt+=n/7;
		int x=n%7;
		if (x==1)
		{
			ans[8]--;
			cnt--;
			ans[0]++;
			ans[1]++;
			cnt+=2;
		}
		if (x!=0&&x!=1)
		{
			for (int i=1;i<=9;i++)
			{
				if (amount[i]==x)
				{
					ans[i]++;
					cnt++;
					break;
				}
			}
		}
		for (int i=2;i<=9;i++)
		{
			if (ans[i]>0)
			{
				cout<<i;
				ans[i]--;
				cnt--;
				break;
			}
		}
		for (int i=1;i<=9;i++)
		{
			while (ans[i]>0)
			{
				cout<<i;
				ans[i]--;
				cnt--;
			}
			if (cnt==0)
			{
				break;
			}
		}
		cout<<endl;
	}
	return 0;
}
