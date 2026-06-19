#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[110];
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
		cin >> a[i];
	int p = a[1];
	sort(a,a+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++)
		a[i] = a[i];
	int cnt;
	for (int i = 1;i <= n*m;i++)
	{
	    if (a[i] == p)
	 	{
	 	    cnt = i;
	 		break;
		}
   }
	if (cnt <= n && m == 1) //m=1
		cout << 1 << " " << cnt;
	else if (n == 1) //n=1
		cout << cnt << " " << 1;
	else if (cnt >= n + 1 && cnt <= 2*n) 
		cout << 2 << " " << cnt - m + 1;
	else if (cnt >= 2*n + 1 && cnt <= 3*n)
		cout << 3 << " " << cnt - (m-1) * n;
		
	return 0;
}
