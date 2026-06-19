#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll T;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ll n;
		cin>>n;
		if(n == 1)
		{
			cout<<-1<<endl;
			continue;
		}
		ll x = n % 7;
		switch(x)
		{
			case 0:
				for(int i = 1;i <= n / 7;i++)
					cout<<8;
				cout<<endl;
				break;
			case 1:
				cout<<10;
				for(int i = 1;i < n / 7;i++)
					cout<<8;
				cout<<endl;
				break;
			case 2:
				cout<<1;
				for(int i = 1;i <= n / 7;i++)
					cout<<8;
				cout<<endl;
				break;
			case 3:
				if(n / 7 >= 2)
				{
					cout<<200;
					for(int i = 1;i <= n / 7 - 2;i++)
						cout<<8;
					cout<<endl;
				}
				else if(n / 7 == 1)
					cout<<22<<endl;
				else
					cout<<7<<endl;
				break;
			case 4:
				if(n / 7 >= 1)
				{
					cout<<20;
					for(int i = 1;i < n / 7;i++)
						cout<<8;
					cout<<endl;
				}
				else
					cout<<4<<endl;
				break;
			case 5:
				cout<<2;
				for(int i = 1;i <= n / 7;i++)
					cout<<8;
				cout<<endl;
				break;
			case 6:
				cout<<6;
				for(int i = 1;i <= n / 7;i++)
					cout<<8;
				cout<<endl;
				break;
		}
	}
    return 0;
}
