#include <bits/stdc++.h>
using namespace std;

int a[25],p[25],n,t,ax=0;
int red,blue,cnt=0;
void check()
{
	cnt=0,red=0,blue=0;
	for(int i = 1; i <= n; i++)
	{
		if(p[i]==1)
		{
			if(a[red]==a[i]) cnt+=a[i];
			red=i;
		}
		if(p[i]==0)
		{
			if(a[blue]==a[i]) cnt+=a[i];
			blue=i;
		}
	}
	ax=max(cnt,ax);
	return;
}

void dfs(int step)
{
	if(step>n)
	{
		check();
		return;
	}
	p[step]=1;
	dfs(step+1);
	p[step]=0;
	dfs(step+1);

}



int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	for(int wawawa = 1; wawawa <= t; wawawa++)
	{
		ax=0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			
		}
		dfs(1);
		cout << ax << endl;
	}
	
}
