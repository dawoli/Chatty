#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	int a[11];
	for(int o=1;o<=T;o++)
	{
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1;
			continue;
		}
		while(n>=0)
		{
			if(n==0) break;
			if(n==17) a[2]++,a[0]+=2;
			else if(n>=14) a[8]++,n-=7;
			else
			{
				if(n==13) a[6]++,a[8]++;
				if(n==12) a[2]++,a[8]++;
				if(n==11) a[2]++,a[0]++;
				if(n==10) a[2]++,a[2]++;
				if(n==9) a[1]++,a[8]++;
				if(n==8) a[1]++,a[0]++;
				if(n==7) a[8]++;
				if(n==6) a[6]++;
				if(n==5) a[2]++;
				if(n==4) a[4];
				if(n==3) a[7]++;
				if(n==2) a[1]++;
			}
		}
		for(int i=0;i<=9;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		bool flag=true;
		for(int i=0;i<=9;i++)
		{
			if(flag=true&&a[0]!=0)
			{
				for(int j=1;j<=9;j++)
				{
					if(a[i]!=0) cout<<i,flag=false;
				}
			}
			else
			{
				while(a[i]!=0) cout<<i,a[i]--;
			}
		}
		cout<<endl;
	}
}
