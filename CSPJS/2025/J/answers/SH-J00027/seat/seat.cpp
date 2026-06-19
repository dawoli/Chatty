#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int rn,rs;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	rs=a[1]; 
	rn=1;
	if(n==1&&m==1)//p1 
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	sort(a+1,a+n*m+1);
	int b[110];
	for(int i=n*m,j=1;i>=1;i--,j++)
	{
		b[i]=a[j];
	}
	int k=1;
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<b[i]<<endl;
//	}
	for(int i=1;i<=n*m;i++)//ÆäÓà 
	{
	 	if(a[i]==rs)
	 	{
	 		rn=n*m-i+1;
	 		break;
		}
	}
//	cout<<rn<<endl;
	while(rn>n)
	{
		rn-=n;
		k+=1;
	}
	if(k%2==1)
	{
		cout<<k<<" "<<rn<<endl;
	}
	else
	{
		cout<<k<<" "<<n-rn+1<<endl;
	}
	return 0;
 } 
