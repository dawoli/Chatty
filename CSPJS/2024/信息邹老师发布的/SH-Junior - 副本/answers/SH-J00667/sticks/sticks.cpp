#include<bits/stdc++.h>
using namespace std;

int requires[10] = {6,2,5,5,4,5,6,3,7,6};

int main()
{
	int T,n;
	cin>>T;
	while(T --)
	{
		cin>>n;
		if(n < 10)
		{
			for(int i = 0;i < n;i ++)
				if(requires[i] == n)
				{
					cout<<i;
					return 0;
				}
			if(n % 7 == 0)
			{
				for(int i = 0;i < n / 7;i ++)
					cout<<12;
				return 0;
			}
			if((n - 1) % 7 == 0)
			{
				int k = (n - 1) / 7;
				if(k <= 6)
				{
					for(int i = 0;i < 10;i ++)
						if(requires[i] == k + 1){cout<<i;break;}
					for(int i = 0;i < n;i ++)cout<<0;
					return 0;
				}
			}
		}
	}
	return 0;
}
