#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int main()
{
	cin>>n>>m>>a;
	int cnt=1;
	for(int i=2;i<=n*m;i++)
	{
		int x;
		cin>>x;
		if(x>a)
			cnt++;
	}
	int r;
	int c=(cnt+n-1)/n;
	if(c%2==1)
		r=cnt%(2*n);
	else
		r=(2*n+1)-(cnt%(2*n));
	cout<<c<<" "<<r;
	return 0;
}
