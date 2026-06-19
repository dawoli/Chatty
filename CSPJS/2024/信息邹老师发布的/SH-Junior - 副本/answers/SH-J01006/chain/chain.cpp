#include <bits/stdc++.h>
using namespace std;
int s[1010][1010],l[100010];
int n,k,q;
bool sol(int nr,int now,int r,int c)
{
	bool retu = 0;
	for(int j = 1;j <= n;j++)//第几个人 
	{
		for(int o = 1; o <= l[j]-2; o++)//开头 
		{
			if(s[j][o] != now)
			continue;
			for(int m = 1; m + o < l[j] && m < k;m++)
			{//长度 
				if(nr == r)
				{
					retu = s[j][m + o] == c;
				}
				retu = retu || sol(nr+1,s[j][m + o],r,c);
			}
		}
	}
	return retu;
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++)
		{
			cin >> l[i];
			for(int j = 1;j <= l[i];j++)
			{
				cin >> s[i][j];
			}
		}
		for(int i = 1;i <= q;i++)
		{
			int r,c;
			cin >> r >> c;
			bool ans = sol(1,1,r,c);
			if(ans)
			cout << 1 << endl;
			else
			cout << 0 << endl;
		}
	}
	return 0;
}
