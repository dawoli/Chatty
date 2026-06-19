#include <bits/stdc++.h>
using namespace std;
int a[105];
int m=1,n=1,flag = 1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin >> c >> r;
	cin >> a[0];
	int p = a[0],x=0;
	for(int i=1;i<c*r;i++)
	{
		cin >> a[i];
	}
	sort(a,a+c*r,cmp);
	while(p!=a[x])
	{
		if(m+flag>=1&&m+flag<=c)
		{
			m+=flag;
			x++;
			continue;
		}
		n++;
		x++;
		flag*=-1;
	}
	cout << n << ' ' << m << endl;
	return 0;
}
