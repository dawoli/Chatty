#include <bits/stdc++.h>
using namespace std;
int n,m,score,s;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	score=a[1];
	sort(a+1,a+n*m+1); 
	int l=1,r=n*m;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<score)
			l=mid+1;
		else
			r=mid;
	}
	int h=0,c=0;
	if(l==r)
	{
		s=n*m-l+1;
		if(s%n>0)
			h=s/n+1;
		else
			h=s/n;
		if(h%2==1)
		{
			if(s%n==0)
				c=n;
			else
				c=s%n;
		}
		else
		{
			if(s%n==0)
				c=1;
			else
				c=n-s%n+1;
		}
	}
	cout << h << ' ' << c;
	return 0;
}
