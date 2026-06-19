#include<bits/stdc++.h>
using namespace std;
bool a[10][30]={0};
int n,k,p,cnt=0;
string s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='D')  k=1;
		else if(s[0]=='C')  k=2;
		else if(s[0]=='H')  k=3;
		else  k=4;
		if(s[1]=='A')  p=1;
		else if(s[1]=='T')  p=10;
		else if(s[1]=='J')  p=11;
		else if(s[1]=='Q')  p=12;
		else if(s[1]=='K')  p=13;
		else  p=s[1]-'0';
		a[k][p]=1;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]==0)  cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
