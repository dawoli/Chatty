#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],score,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		score=a[1];
		if(a[i]>score)
		{
			cnt++;
		}
	}
	int c=cnt/m+1,r=0;
	if(c%2==0)
	{
		r=n-cnt%m;
	}
	else
	{
		r=cnt%m+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
