#include<bits/stdc++.h>
using namespace std;
bool flag;
int T, n, k, q, l[200005];
map<int, map<int, int> > s;
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		for(int i = 1; i <= n; i++)
		{
			cin>>l[i];
			for(int j = 1; j <= l[i]; j++) cin>>s[i][j];
		}
		while(q--)
		{
			int r, c;
			cin>>r>>c;
			if(r == 1)
			{
				flag = 0;
				for(int i = 1; i <= n; i++)
				{
					for(int j = 1; j <= l[i]; j++)
					{
						for(int u = 1; u < k; u++)
						{
							if(s[i][j] % (u * 10) == c) 
							{
								flag = 1;
								break;
							}
						}
						if(flag == 1) break;
					}
					if(flag == 1) break;
				}
				if(flag == 1) cout<<1<<endl;
				else cout<<0<<endl;
			}
			else{
				cout<<r%2<<endl;
			}
		}
	}
	return 0;
}
