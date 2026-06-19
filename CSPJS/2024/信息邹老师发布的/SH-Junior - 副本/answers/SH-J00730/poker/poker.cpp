#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
bool D[14],C[14],H[14],S[14];
int input(char x)
{
	if(x=='A')
		return 1;
	if(x=='T')
		return 10;
	if(x=='J')
		return 11;
	if(x=='Q')
		return 12;
	if(x=='K')
		return 13;
	if(x>='2'&&x<='9')
		return int(x-'0');
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s[0]=='D')
		{
			D[input(s[1])]=true;
		}
		if(s[0]=='C')
		{
			C[input(s[1])]=true;
		}
		if(s[0]=='H')
		{
			H[input(s[1])]=true;
		}
		if(s[0]=='S')
		{
			S[input(s[1])]=true;
		}
	}
	int ans=0; 
	for(int i=1;i<=13;i++)
	{
		if(!D[i])
			ans++;
		if(!C[i])
			ans++;
		if(!H[i])
			ans++;
		if(!S[i])
			ans++;
		
	}
	printf("%d",ans);
	return 0;
}

