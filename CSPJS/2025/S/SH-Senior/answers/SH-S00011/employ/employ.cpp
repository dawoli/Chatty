#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int sum = 0;
	for(int i = 0;i<n;i++)
		if(s[i]=='1')
			sum++;
	if(sum<m)
		cout<<0;
	else
	{
		vector<int> a;
		for(int i = 0;i<n;i++)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		long long ans = 1;
		if(m==sum)
		{
			for(int i = 0;i<n;i++)
			{
				ans*=i+1;
				ans%=998244353;
						cout<<ans;
			}
		}

	}
	return 0;
}
