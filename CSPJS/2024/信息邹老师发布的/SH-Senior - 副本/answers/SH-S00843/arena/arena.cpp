#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
int b[N];
int c[N];
int x[4];
int n,m;
string s[20];

int main()
{
	freopen("arena.in" , "r" , stdin);
	freopen("arena.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d" , &a[i]);
	}
	for(int i = 1;i <= m;i++)
	{
		scanf("%d" , &c[i]);
	}
	int j = 0;
	for(int i = 1;i < n;i <<= 1)
	{
		j++;
		cin >> s[j];
	}
	int t;
	scanf("%d" , &t);
	while(t--)
	{
		int ans = 0;
		for(int i = 0;i < 4;i++) scanf("%d" , &x[i]);
		for(int i = 1;i <= n;i++)
		{
			b[i] = a[i]^x[i%4];
		}
		for(int i = 1;i <= m;i++)
		{
			bool flag[N];
			bool tf = 0;
			int num = 0;
			int pre = 0;
			int win = 0;
			memset(flag , 0 , sizeof flag);
			for(int j = 1;j < c[i]; j <<= 1)
			{
				num = 0;
				pre = 0;
				tf = 0;
				for(int k = 1;k <= n;k++)
				{
					if(flag[k]) continue;
					if(tf)
					{
						if(s[j][num] == '1')
						{
							if(b[k] >= k)
							{
								flag[pre] = 1;
								win = k;
							}else{
								flag[k] = 1;
								win = pre;
							}
						}else
						{
							if(b[pre] >= k)
							{
								flag[k] = 1;
								win = pre;
							}else{
								flag[pre] = 1;
								win = k;
							}
						} 
						tf = 0;
						num++;
					}else{
						tf = 1;
						pre = k;
					}
				}
			}
			ans += win^i; 
		}
		cout << ans << endl;
	}
	return 0;
}
