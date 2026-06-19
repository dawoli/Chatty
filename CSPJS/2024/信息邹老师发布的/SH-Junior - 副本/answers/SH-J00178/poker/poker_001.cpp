#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
string a;
bool flag[5][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a[0]=='D')
		{
			if(a[1]=='A') flag[1][1]=1;
			if(a[1]=='2') flag[1][2]=1;
			if(a[1]=='3') flag[1][3]=1;
			if(a[1]=='4') flag[1][4]=1;
			if(a[1]=='5') flag[1][5]=1;
			if(a[1]=='6') flag[1][6]=1;
			if(a[1]=='7') flag[1][7]=1;
			if(a[1]=='8') flag[1][8]=1;
			if(a[1]=='9') flag[1][9]=1;
			if(a[1]=='T') flag[1][10]=1;
			if(a[1]=='J') flag[1][11]=1;
			if(a[1]=='Q') flag[1][12]=1;
			if(a[1]=='K') flag[1][13]=1;
		}
		if(a[0]=='C')
		{
			if(a[1]=='A') flag[2][1]=1;
			if(a[1]=='2') flag[2][2]=1;
			if(a[1]=='3') flag[2][3]=1;
			if(a[1]=='4') flag[2][4]=1;
			if(a[1]=='5') flag[2][5]=1;
			if(a[1]=='6') flag[2][6]=1;
			if(a[1]=='7') flag[2][7]=1;
			if(a[1]=='8') flag[2][8]=1;
			if(a[1]=='9') flag[2][9]=1;
			if(a[1]=='T') flag[2][10]=1;
			if(a[1]=='J') flag[2][11]=1;
			if(a[1]=='Q') flag[2][12]=1;
			if(a[1]=='K') flag[2][13]=1;
		}
		if(a[0]=='H')
		{
			if(a[1]=='A') flag[3][1]=1;
			if(a[1]=='2') flag[3][2]=1;
			if(a[1]=='3') flag[3][3]=1;
			if(a[1]=='4') flag[3][4]=1;
			if(a[1]=='5') flag[3][5]=1;
			if(a[1]=='6') flag[3][6]=1;
			if(a[1]=='7') flag[3][7]=1;
			if(a[1]=='8') flag[3][8]=1;
			if(a[1]=='9') flag[3][9]=1;
			if(a[1]=='T') flag[3][10]=1;
			if(a[1]=='J') flag[3][11]=1;
			if(a[1]=='Q') flag[3][12]=1;
			if(a[1]=='K') flag[3][13]=1;
		}
		if(a[0]=='S')
		{
			if(a[1]=='A') flag[4][1]=1;
			if(a[1]=='2') flag[4][2]=1;
			if(a[1]=='3') flag[4][3]=1;
			if(a[1]=='4') flag[4][4]=1;
			if(a[1]=='5') flag[4][5]=1;
			if(a[1]=='6') flag[4][6]=1;
			if(a[1]=='7') flag[4][7]=1;
			if(a[1]=='8') flag[4][8]=1;
			if(a[1]=='9') flag[4][9]=1;
			if(a[1]=='T') flag[4][10]=1;
			if(a[1]=='J') flag[4][11]=1;
			if(a[1]=='Q') flag[4][12]=1;
			if(a[1]=='K') flag[4][13]=1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(flag[i][j]==0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
