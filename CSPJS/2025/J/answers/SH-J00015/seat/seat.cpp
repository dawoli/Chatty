#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int cnt=n*m;
	for(int i=1;i<=cnt;i++)cin>>a[i];
	int sum=a[1];
	sort(a+1,a+1+cnt,greater<int>());
	int x=1;
	int y=1;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]!=sum){
			if(x%2==1){
				y++;
				if(y>n)
				{
					x++;
					y=n;
				}
			}
			else {
				y--;
				if(y<1)
				{
					x++;
					y=1;
				}
			}
			
		}
		else 
		{
			cout<<x<<" "<<y;
			return 0;
		}
		
		
	}
	fclose(stdin);
	fclose(stdout);
 } 
