#include<bits/stdc++.h>
using namespace std;
int t;
long long l,y,k,d;
string arr[1111];
bool check(int x1,int y1)
{
	if(x1>l||y1>y) return false;
	return true;
}
int movex(int x2,int d)
{
	if(d==0||d==2) return x2;
	else if(d==1) return x2+1;
	else return x2-1;
} 
int movey(int y2,int d)
{
	if(d==1||d==3) return y2;
	else if(d==0) return y2+1;
	else return y2-1;
} 
int main()
{
	freopen("explore.in",'r',stdin);
	freopen("explore.out",'w',stdout);
	cin>>t;
	while(t--)
	{
		int ans = 1;
		int x0,y0;
		cin>>l>>y>>k;
		cin>>x0>>y0>>d;
		for(int i=1;i<=l;i++) 
			for(int j=1;j<=y;j++) 
				cin>>arr[i][j];
		while(k--)
		{
			int x1 = movex(x0,d);
			int y1 = movey(y0,d);
			if(check(x1,y1)&&arr[x1][y1]=='.') 
			{
				ans++;
				arr[x0][y0] = 'l';
				x0 = x1;
				y0 = y1;
			}
			else if(check(x1,y1)&&arr[x1][y1]=='l')
			{
				x0 = x1;
				y0 = y1;
			}
			else d = (d+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
