#include<bits/stdc++.h>
using namespace std;
int ans,n,t;
int a[20];
bool b[20];
void dfs(int x,int y)
{
	if(x >= n)
	{
		ans = max(ans,y);
		return;
	}
	if(x == n-1)
	{
		
		for(int i=0;i<n;i++)
		{
			if(b[i] == 0)
			{
				int j = i-1;
				while(j >= 0 && b[j] == 1) j--;
				if(j != -1 && a[j] == a[i])
				{
					y += a[i]; 
				}
			}
			if(b[i] == 1)
			{
				int j = i-1;
				while(j >= 0 && b[j] == 0) j--;
				if(j != -1 && a[j] == a[i])
				{
					y += a[i];
				}
			}
		}
	}
	b[x] = 0;
	dfs(x+1,y);
	b[x] = 1;
	dfs(x+1,y);
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		ans = 0;
		dfs(0,0);
		cout << ans << endl;
	}
	return 0;
} 
