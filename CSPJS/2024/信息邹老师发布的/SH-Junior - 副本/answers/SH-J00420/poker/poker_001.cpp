#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string a;
	bool f[55]={0};
	if(n==0)
	{
		cout<<52;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int cnt=0;
		if(a[0]=='D')
		{
			cnt+=0;
			if(a[1]-'0'>1&&a[1]-'0'<=9)
			{
				cnt+=(a[1]-'0');
			}
			if(a[1]=='A')
			{
				cnt+=1;
			}
			if(a[1]=='T')
			{
				cnt+=10;
			}
			if(a[1]=='J')
			{
				cnt+=11;
			}
			if(a[1]=='Q')
			{
				cnt+=12;
			}
			if(a[1]=='K')
			{
				cnt+=13;
			}
		}
		else if(a[0]=='C')
		{
			cnt+=13;
			if(a[1]-'0'>1&&a[1]-'0'<=9)
			{
				cnt+=(a[1]-'0');
			}
			if(a[1]=='A')
			{
				cnt+=1;
			}
			if(a[1]=='T')
			{
				cnt+=10;
			}
			if(a[1]=='J')
			{
				cnt+=11;
			}
			if(a[1]=='Q')
			{
				cnt+=12;
			}
			if(a[1]=='K')
			{
				cnt+=13;
			}
		}
		else if(a[0]=='H')
		{
			cnt+=26;
			if(a[1]-'0'>1&&a[1]-'0'<=9)
			{
				cnt+=(a[1]-'0');
			}
			if(a[1]=='A')
			{
				cnt+=1;
			}
			if(a[1]=='T')
			{
				cnt+=10;
			}
			if(a[1]=='J')
			{
				cnt+=11;
			}
			if(a[1]=='Q')
			{
				cnt+=12;
			}
			if(a[1]=='K')
			{
				cnt+=13;
			}
		}
		else if(a[0]=='S')
		{
			cnt+=39;
			if(a[1]-'0'>1&&a[1]-'0'<=9)
			{
				cnt+=(a[1]-'0');
			}
			if(a[1]=='A')
			{
				cnt+=1;
			}
			if(a[1]=='T')
			{
				cnt+=10;
			}
			if(a[1]=='J')
			{
				cnt+=11;
			}
			if(a[1]=='Q')
			{
				cnt+=12;
			}
			if(a[1]=='K')
			{
				cnt+=13;
			}
		}
		f[cnt]=1;
	}
	int sum=0;
	for(int i=1;i<=52;i++)
	{
		if(f[i]==0)
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
