#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200],k,p,q;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			k=i;
			i=n*m;
		}
	}
	if(k%n==0)p=k/n;
	else p=k/n+1;
	if(p%2==1 )q=k%n;
	if(p%2==1 and k%n==0)q=n;
	if(p%2==0)q=n-k%n+1;
	if(p%2==0 and k%n==0)q=1;
	cout<<p<<" "<<q;
}
