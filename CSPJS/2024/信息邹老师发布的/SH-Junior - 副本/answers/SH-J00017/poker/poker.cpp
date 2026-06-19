#include<bits/stdc++.h>
using namespace std;
int g(string s)
{
	switch(s[1])
	{
		case 'A':return 1;
		case 'T':return 10;
		case 'J':return 11;
		case 'Q':return 12;
		case 'K':return 13;
	}
	
	return int(s[1])-48;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int a[56]={0},n,c=0;
	string s;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='D')
		{
			a[g(s)]=1;
		}
		if(s[0]=='C')
		{
			a[13+g(s)]=1;
		}
		if(s[0]=='H')
		{
			a[26+g(s)]=1;
		}
		else
		{
			a[39+g(s)]=1;
		}
	}
	for(int i=1;i<53;i++)
	{
		if(!a[i])
		{
			c++; 
		}
	}
	printf("%d",c);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
