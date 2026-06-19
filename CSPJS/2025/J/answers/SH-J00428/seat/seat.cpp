#include<iostream>
using namespace std;


int m,n;
int a[105];
int cnt=0;
int ansx,ansy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	for(int i=2;i<=m*n;i++)
	{
		if(a[i]>=a[1])cnt++; 
	}
	cnt++;
	for(int i=1;i<=m;i++)
	{
		if(cnt<=n)
		{
			if(i%2==1)
			{
				ansx=i;
				ansy=cnt;
				break;
			}
			else{
				ansx=i;
				ansy=n-cnt+1;
				break;
			}
		}	
		cnt-=n;
	}
	cout<<ansx<<' '<<ansy;
	return 0;
 } 
