#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;

const int N = 1e5 + 5;
int n,k,q,r,c;
vector<int> s[N];
bool flag = false;

void dfs(int step,int num,int ren)
{
	if(step > r)
	{
		if(num == c) flag = true;
		return;
	}
	for(int peo = 1;peo <= n;peo++)
	{
		if(peo == ren) continue;
		for(int f = 1;f <= s[peo][0];f++)
		{
			if(s[peo][f] == num)
			{
				for(int i = 1;i < k && f + i <= s[peo][0];i++)
				{
					// cout << step << " " << peo << " " << f + i << endl;
					dfs(step + 1,s[peo][f + i],peo);
				}
			}
		}
	}
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++)
		{
			int l;
			cin >> l;
			s[i].push_back(l);
			for(int j = 1;j <= l;j++)
			{
				int a;
				cin >> a;
				s[i].push_back(a);
			}
		}
		while(q--)
		{
			flag = false;
			cin >> r >> c;
			if(r == 1)
			{
				for(int i = 1;i <= n;i++)
				{
					for(int j = 1;j <= s[i][0];j++)
					{
						if(s[i][j] == 1)
						{
							for(int l = 1;l < k;l++)
							{
								if(s[i][j + l] == c)
								{
									// cout << i << " " << j + l << endl;
									flag = true;
									break;
								}
							}
						}
					}
				}

			}
			else if(r <= 10)
			{
				dfs(1,1,0);
			}
			if(!flag) cout << 0;
			else cout << 1;
			cout << endl;
		}
		for(int i = 1;i <= n;i++) s[i].clear();
	}
	return 0;
}
