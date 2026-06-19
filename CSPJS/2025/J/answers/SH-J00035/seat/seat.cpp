#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+n*m+1);
	int s=lower_bound(a+1,a+n*m+1,c)-a;
	s=n*m-s+1;
	if(s%(n*2)==0) cout<<s/n<<" "<<1<<endl; 
	else
	{
		int h=0,l=0;
		h=(s+n-1)/n;
		if(s%(n*2)<=n) l=s%(n*2);
		else 
		{
			l=n*2-s%(n*2)+1;
		}
		cout<<h<<" "<<l<<endl;
	}
	return 0;
}
