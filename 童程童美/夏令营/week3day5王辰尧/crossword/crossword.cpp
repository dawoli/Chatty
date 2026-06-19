#include<bits/stdc++.h>
using namespace std;
int r,c,cnt1,cnt2;
char a[21][21];
string b[500];
bool rec(char a)
{
	if('a'<=a&&a<='z')return 1;
	return 0;
}
int main()
{
	freopen("crossword.in","r",stdin);
	freopen("crossword.out","w",stdout);
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)cin>>a[i][j];
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(cnt2>=2&&rec(a[i][j]))
			{
				cnt2++;
				b[cnt1]==b[cnt1]+a[i][j];
			}			
			if(!cnt2&&rec(a[i][j])&&rec(a[i][j+1]))
			{
				cnt1++;
				b[cnt1]=b[cnt1]+a[i][j]+a[i][j+1];
				cnt2+=2;
				j++;
			}
			if(!rec(a[i][j]))cnt2=0;
		}
		cnt2=0;
	}
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=r;j++)
		{
			if(cnt2>=2&&rec(a[i][j]))
			{
				cnt2++;
				b[cnt1]==b[cnt1]+a[i][j];
			}			
			if(!cnt2&&rec(a[i][j])&&rec(a[i][j+1]))
			{
				cnt1++;
				b[cnt1]=b[cnt1]+a[i][j]+a[i][j+1];
				cnt2+=2;
				j++;
			}
			if(!rec(a[i][j]))cnt2=0;
		}
		cnt2=0;
	}
	sort(b+1,b+cnt1);
	cout<<b[1];
	return 0;	
}
