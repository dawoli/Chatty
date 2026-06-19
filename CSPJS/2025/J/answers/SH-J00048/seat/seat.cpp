#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int xs;
	cin >> xs;
	int w=1;
	for(int i=1;i<n*m;i++)
	{
		cin >> s[i];
		if(s[i]>xs)
		{
			w++;
		}
	}
	int flag=0;
	int c=1,r=1;
	for(int i=2;i<=w;i++)
	{
		if(flag==0)
		{
			r++;
		}
		else
		{
			r--;
		}
		if(r>m&&flag==0)
		{
			c++;
			r--;
			flag=1;
		}
		else if(r<1&&flag==1)
		{
			c++;
			r++;
			flag=0;
		}
	}
	cout << c << " " << r;
	return 0;
	fclose(stdin);
	fclose(stdout);	
}
