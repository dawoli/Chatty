#include<bits/stdc++.h>
using namespace std;
int a[101],b[1001][1001];

		
		
					

int main()
{
freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int cnt=0,m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];		
	}
	int a1=a[1];
	for(int i=1;i<=m*n;i++)
	{int temp =0;
		if(a[i]<=a[i+1])
		{
		temp=a[i];
		a[i]=a[i+1];
		a[i+1]=temp;	
		}
	}
	for(int j=1;j<=n;j++)
		{
			if(j%2==1)
			{
			for(int i=1;i<=m;i++)
			{
			b[i][j]=a[cnt++];
			cnt++;	
				}	
				}
				else
				{
					for(int i=m;i>=1;i--)
					{
						 b[i][j]=a[cnt++] ;
						cnt++;
					}
					}
				}
	for(int c=1;c<=m;c++)
	{
		for(int r=1;r<=n;r++){
			if(a1==b[c][r])
			{
				cout<<r<<" "<<c;
				break;
			}
		}
				}			
	return 0;
}
