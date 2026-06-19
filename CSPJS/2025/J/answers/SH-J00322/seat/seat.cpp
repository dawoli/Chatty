#include<bits/stdc++.h>
using namespace std;
int n,m,s,nm,cnt,r,h,l,a[15][15];
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m,cnt=0;
	cin>>r;
	for(int i=1;i<nm;i++)
	{
		cin>>s;
		if(s>r) cnt++;
	}
	cnt++;

	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				cnt--;
				if(cnt==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt--;
				if(cnt==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	} 
	cout<<l<<" "<<h;
	return 0;
}
