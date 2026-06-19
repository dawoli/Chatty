#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
			cout<<-1<<'\n';
		else if(n==2)
			cout<<1<<'\n';
		else if(n==3)
			cout<<7<<'\n';
		else if(n==4)
			cout<<4<<'\n';
		else if(n==5)
			cout<<2<<'\n';
		else if(n==6)
			cout<<6<<'\n';
		else if(n==7)
			cout<<8<<'\n';
		else if(n==8)
			cout<<10<<'\n';
		else if(n==9)
			cout<<18<<'\n';
		else if(n==10)
			cout<<23<<'\n';
		else if(n==11)
			cout<<20<<'\n';
		else if(n==12)
			cout<<28<<'\n';
		else if(n==13)
			cout<<67<<'\n';
		else
		{
			int m=n%7;
			int k=n/7;
			if(m==0)
			{
				for(int i=1;i<=k;i++)
					cout<<"8";
				cout<<'\n';
			}
			else if(m==1)
			{
				cout<<"10";
				for(int i=1;i<k;i++)
					cout<<"8";
				cout<<'\n';
			}
			else if(m==2)
			{
				cout<<"1";
				for(int i=1;i<=k;i++)
					cout<<"8";
				cout<<'\n';
			}
			else if(m==3)
			{
				cout<<"7";
				for(int i=1;i<=k;i++)
					cout<<"8";
				cout<<'\n';
			}
			else if(m==4)
			{
				cout<<"20";
				for(int i=1;i<k;i++)
					cout<<"8";
				cout<<'\n';
			}
			else if(m==5)
			{
				cout<<"2";
				for(int i=1;i<=k;i++)
					cout<<"8";
				cout<<'\n';
			}
			else if(m==6)
			{
				cout<<"6";
				for(int i=1;i<=k;i++)
					cout<<"8";
				cout<<'\n';
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
