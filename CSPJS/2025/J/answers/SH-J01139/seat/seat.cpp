#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=n*m;
	int a[q];
	for(int i=0;i<q;i++)
	{
		cin>>a[i];
	}
	int w=a[0];
	int x=1,y=1;
	bool flag1=true;
	for(int i=1;i<q;i++)
	{
		if(w>a[i])
		{
			break;
		}
		if(flag1==true)
		{
			if(y+1<=n) y++;
			else{
				y=1;
				x++;
				flag1=false;
			}
		}
		if(flag1==false)
		{
			if(y-1>1) y--;
			else{
				y=n;
				x++;
				flag1=true;
			}
		}
	}
	if(x>m) x=m;
	if(y>n) y=n;
	cout<<x<<" "<<y;
	return 0;
}
