#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		int m=0,sum=n;
		while(7*m<n)m++;
		bool b=false;
		for(int i=m-1;i>=0;i--)
		{
			int x=sum-7*i;
			if(i==0)
			{
				if(x==2)a[1]++;
				else if(x==3)a[7]++;
				else if(x==4)a[4]++;
				else if(x==5)a[2]++;
				else if(x==6)
				{
					if(b)a[0]++;
					else a[6]++;
				}
				else if(x==7)a[8]++;
			}
			else if(b&&sum%6==0&&sum/6<7)
			{
				a[0]++;
				sum-=6;
			}
			else if(x<=2)
			{
				a[1]++;
				sum-=2;
			}
			else if(x<=5)
			{
				a[2]++;
				sum-=5;
			}
			else if(x<=6)
			{
				if(b)a[0]++;
				else a[6]++;
				sum-=6;
			}
			else if(x<=7)
			{
				a[8]++;
				sum-=7;
			}
			b=true;
		}
		b=false;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(a[j])
				{
					if(!b&&j==0)continue;
					cout<<j;
					a[j]--;
					b=true;
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
