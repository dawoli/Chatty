#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,y=0,x=0;
string str;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		if(str[0]=='H')
			x=1;
		if(str[0]=='D')
			x=2;
		if(str[0]=='C')
			x=3;
		if(str[0]=='S')
			x=4;
		if(str[1]>='2'&&str[1]<='9')
			y=str[1]-'0';
		if(str[1]=='A')
			y=1;
		if(str[1]=='T')
			y=10;
		if(str[1]=='J')
			y=11;
		if(str[1]=='Q')
			y=12;
		if(str[1]=='K')
			y=13;
		a[x][y]=1;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(a[i][j]==0)
				ans++;
	cout<<ans<<endl;
	return 0;
}
