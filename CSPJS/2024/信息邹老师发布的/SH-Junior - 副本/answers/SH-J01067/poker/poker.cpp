# include <bits/stdc++.h>
using namespace std;
bool flag[4][14]={0};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int j;
		if(s[0]=='D')
		{
			j=0;
		}
		if(s[0]=='C')
		{
			j=1;
		}
		if(s[0]=='H')
		{
			j=2;
		}
		if(s[0]=='S')
		{
			j=3;
		}
		if(s[1]=='T')
		{
			flag[j][10]=1;
		}
		else if(s[1]=='J')
		{
			flag[j][11]=1;
		}
		else if(s[1]=='Q')
		{
			flag[j][12]=1;
		}
		else if(s[1]=='K')
		{
			flag[j][13]=1;
		}
		else if(s[1]=='A')
		{
			flag[j][1]=1;
		}
		else
		{
			flag[j][s[1]-'0']=1;
		}
	}
	int sum=0;
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(flag[i][j]==0)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
