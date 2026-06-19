#include <bits/stdc++.h>
using namespace std;
struct node
{
	int n ,id;
};
node a[205];
bool cmp(node x,node y)
{
	return x.n>y.n;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m;
	cin >> n >>m;
	for(int i = 1; i <= n*m;i++)
	{
		cin >> a[i].n;
		a[i].id = i;
	}
	int f =  a[1].n;
	sort(a+1,a+1+n*m,cmp);
	int ans;
	for(int i = 1; i <= n*m; i++)
	{
		if(a[i].n == f)
		{
			ans = i;
			break;
		}
	}
	if((ans+n-1)/n%2==1)
	{
		cout << (ans+n-1)/n<<" ";
		if(ans%n==0)
		{
			cout << n;
		}
		else
		{
			cout << ans%n;
		}
	}
	else
	{
		cout << (ans+n-1)/n<<" ";
		if(ans%n==0)
		{
			cout << 1;
		}
		else
		{
			cout << n+1-(ans%n);
		}
	}
	return 0;
}
