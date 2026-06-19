#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> m >> n;
	int sum=m*n,a[sum],x=1,y=1;
	bool f=1;
	cin >> a[0];
	int k=a[0];
	for(int i=1;i<sum;i++)
	{
		cin >> a[i];
		if(a[i]>k)
		{
			 if(f)
			 {
			 	y++;
			 	if(y>n)
			 	{
			 		x++;
			 		y--;
			 		f=0;
				}
			 }
			 else
			 {
			 	y--;
			 	if(y<=0)
			 	{
			 		y++;
			 		x++;
			 		f=1;
				}
			 }
		}
	}
 	if(y>n)
	{
	 	x++;
	 	y--;
	}
	else if(y<=0)
	{
		y++;
		x++;
	}
	cout << x << " " << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
