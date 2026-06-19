#include<bits/stdc++.h>
using namespace std;
int m,n,a[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m,num=0;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=k;j++)
	{
		if(a[j]>=a[1])
		{
			num++;
		}
	}
	int x=num%m;
	int y=(num-x)/m;
	int ans;
	if(x==0)
	{
		if(y%2==0)
		{
		cout<<y<<" "<<n-n+1<<endl;
	}
		else
		{
		cout<<y<<" "<<n<<endl;	
	}
}
	else{
if(y%2==0)
	{
		ans=x;
	}
	else
	{
		ans=n-x+1;
	}

	cout<<y+1<<" "<<ans<<endl;
}
	return 0;
 } 
