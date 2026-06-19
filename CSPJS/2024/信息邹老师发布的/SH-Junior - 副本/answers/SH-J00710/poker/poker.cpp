#include <bits/stdc++.h>
using namespace std;
long long n,i,j,cnt=0,ans=52;
long long a[100][10001]={0,0};
char ch1,ch2;
long long count()
{
	cnt=0;
	if(ch1=='D')
		cnt=1;
	if(ch1=='C')
		cnt=2;
	if(ch1=='H')
		cnt=3;
	if(ch1=='S')
		cnt=4;
	if(ch2=='A')
		a[cnt][1]=1;
	if(ch2=='2')
		a[cnt][2]=1;
	if(ch2=='3')
		a[cnt][3]=1;
	if(ch2=='4')
		a[cnt][4]=1;
	if(ch2=='5')
		a[cnt][5]=1;
	if(ch2=='6')
		a[cnt][6]=1;
	if(ch2=='7')
		a[cnt][7]=1;
	if(ch2=='8')
		a[cnt][8]=1;
	if(ch2=='9')
		a[cnt][9]=1;
	if(ch2=='T')
		a[cnt][10]=1;
	if(ch2=='J')
		a[cnt][11]=1;
	if(ch2=='Q')
		a[cnt][12]=1;
	if(ch2=='K')
		a[cnt][13]=1;
		
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ch1>>ch2;
		count();
	}
	for(i=1;i<=4;i++)
		for(j=1;j<=13;j++)
			if(a[i][j]==1)
				ans--;
	cout<<ans;
	return 0;
}
