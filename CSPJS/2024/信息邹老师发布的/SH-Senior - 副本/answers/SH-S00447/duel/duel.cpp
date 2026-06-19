#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[100009];
int sm,bg,ans;

void in()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	return ;
}

void solve()
{
	sm=0;
	bg=1;
	ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) //阶级转换 
		{
			if(bg>sm)
			{
				ans+=sm;
				sm=bg;
				bg=1;
			}
			else
			{
				ans+=bg;
				//sm=sm-bg+bg;
				bg=1;
			}
			continue;
		}
		bg++;
	}
	// 阶级转换 
	if(bg>sm)
	{
		ans+=sm;
	}
	else
	{
		ans+=bg;
	}
	
	cout<<n-ans;
	
	return ;
}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	in();
	solve();
	
	return 0;
} 
