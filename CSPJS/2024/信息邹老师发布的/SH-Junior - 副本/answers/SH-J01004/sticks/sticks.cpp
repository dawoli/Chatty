#include<bits/stdc++.h.>
#include<cstdio>
using namespace std;
int arr[100005];
int num[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=1;i<=100005;i++)
	{
		int x=i;
		while(x!=0)
		{
			int y=x%10;
			arr[i]+=num[y];
			x/=10;
		}
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			continue;
		}
		if(n%7==1)
		{
			cout<<10;
			for(int i=1;i<=n/7-1;i++)
			{
				cout<<8;
			}
			continue;
		}
		bool flag=0;
		for(int i=1;i<=100005;i++)
		{
			if(arr[i]==n)
			{
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

/*
n/num[i] => num[i]的个数
m=n%num[i] => 余下的木棍数  
m/num[j]  
*/
