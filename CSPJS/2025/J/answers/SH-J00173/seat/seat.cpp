#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
 } 
int a[105]; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i]; 
	}
	int r=a[1]; 
	int place;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			place=i; 
		}
	}
	int temp=place/n; 
	int remain=place%n;
	if(remain==0)
	{
		if(temp%2==0)
		{cout<<temp<<' '<<1;}
		else 
		{cout<<temp<<' '<<n;}
	}
	else
	{
		if((temp+1)%2==0)
		{cout<<temp+1<<' '<<n-remain+1;}
		else 
		{cout<<temp+1<<' '<<remain;}
	} 
	return 0;
}
