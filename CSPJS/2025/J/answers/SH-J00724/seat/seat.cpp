#include <bits/stdc++.h>
using namespace std;

int n,m;
//int a[105];
int b[105];
int a1;

bool cmp(int f,int h)
{
	return f > h;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i = 1;i <= n * m;i ++)
	{
		cin>>b[i];
		
		if(i == 1)
		{
			a1 = b[i];
		}
	}
	
	//sort(a + 1,a + n * m + 1,cmp);
	sort(b + 1,b + n * m + 1);
	
	
	int se = lower_bound(b + 1,b + n*m + 1,a1) - b; 
		
	//se;
	
	se = n * m - se + 1;
	
	//cout<<se<<'\n'; 
	
	if(se % n == 0)
	{
		
		if((se / n) % 2 != 0)
		{
			cout<<se/n<<' '<<n<<'\n';
			return 0;
		}
		
		cout<<se/n<<' '<<1<<'\n';
		return 0;
	}
	
//	cout<<se / m + 1<<' '<<se % n<<'\n'; 
	
	
	if((se / n + 1) % 2 != 0)
	{
		cout<<se/n + 1<<' '<<se % n<<'\n';
		return 0;
	}
	
	cout<<se/n + 1<<' '<<n - (se % n) + 1<<'\n';
	
	return 0;
}
