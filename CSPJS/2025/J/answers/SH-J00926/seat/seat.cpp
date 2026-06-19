#include <bits/stdc++.h>
using namespace std;

int n,m,cnt = 1;
int a[200];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		if (a[i] > a[1]) cnt++;
	}
	int c = (cnt+n-1)/n,r;
	if (c % 2)
	{
		r = cnt-(c-1)*n;
	}
	else
	{
		r = c*n-cnt+1;
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
