#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,ans = 52;
bool vis[62];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--)
	{
		string a;
		cin>>a;
		ll x,y,sum;
		switch(a[0])
		{
			case 'D':
				x = 0;
				break;
			case 'C':
				x = 1;
				break;
			case 'H':
				x = 2;
				break;
			case 'S':
				x = 3;
				break;
		}
		if(a[1] >= '2' && a[1] <= '9')
			y = a[1] - '0';
		else
		{
			switch(a[1])
			{
				case 'A':
					y = 1;
					break;
				case 'T':
					y = 10;
					break;
				case 'J':
					y = 11;
					break;
				case 'Q':
					y = 12;
					break;
				case 'K':
					y = 13;
					break;
			}
		}
		sum = 13 * x + y;
		if(!vis[sum])
		{
			ans--;
			vis[sum] = true;
		}
	}
	cout<<ans<<endl;
    return 0;
}
