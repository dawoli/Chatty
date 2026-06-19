#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	string s;
	
	int m,n;
	cin>>n>>m;
	int r;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	r = a[1];
	sort(a+1,a+1+n*m);
	int num;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i] == r)
		{
			num = i;
		}
	}
	int cnt = n*m-num+1;
	int y=cnt%n;
	int x=cnt/n;
	if(y!=0 && cnt>n)
	{
		x++;
	}
	if(y==0)
	{
		y+=n;
	}
	//偶数需要翻转
	if(x%2==0)
	{
		for(int i=0;i<n;i++)
		{
			s += i+1;
		}
		reverse(s.begin(),s.end());
		for(int i=0;i<s.length();i++)
		{
			if(s[i] == y)
			{
				y=i+1;
				break;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
