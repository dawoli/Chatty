#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int T;
	string cls;
	cin >> T;
	while(T--)
	{
		int mathcnt[7]={0};
		int tot=0, ans=0;
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				cin >> cls;
				if(cls=="math")mathcnt[i]++;
			}
			tot+=mathcnt[i];
		}
		long long days;
		int start;
		cin >> days >> start;
		for(int i = start; i <= 7; i++)
		{
			ans+=mathcnt[i-1];
		}
		days-=8-start;
		ans+=(days/7)*tot;
		days%=7;
		for(int i = 1; i <= days; i++)
		{
			ans+=mathcnt[i-1];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
