#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int a[N];
int n;
bool col[N];
int num;

void dfs(int u , int res)
{
	//cout << u << ' ' << res << endl;
	if(u == n){
		num = max(num , res);
		return;
	}
	u++;
	int ans = res;
	for(int i = 0;i <= 1;i++)
	{
		col[u] = i;
		for(int j = u-1;j >= 1;j--)
		{
			if(col[j] == col[u])
			{
				if(a[j] == a[u]) ans += a[u]; 
				break;
			}
		}
		dfs(u , ans);
		ans = res;
	}
}

int main()
{
	freopen("color.in " , "r" , stdin);
	freopen("color.out" , "w" , stdout);
	int t;
	scanf("%d" , &t);
	while(t--)
	{
		memset(col , 0 , sizeof col);
		scanf("%d" , &n);
		num = 0;
		for(int i = 1;i <= n;i++) scanf("%d" , &a[i]);
		dfs(0,0); 
		cout << num << endl;
	}
	return 0;
}
