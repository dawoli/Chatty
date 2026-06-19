#include<bits/stdc++.h>
using namespace std;
int a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a;
		if(i==1)
		{
			R=a;
		}
		else
		{
			if(a>R)ans++; 
		}
	}
	//cout<<ans;
	int x=(ans/m)+1,y;
	if(x%2==0) y=m-ans%m;
	else y=ans%m+1;
	cout<<x<<" "<<y;
	return 0;
}
