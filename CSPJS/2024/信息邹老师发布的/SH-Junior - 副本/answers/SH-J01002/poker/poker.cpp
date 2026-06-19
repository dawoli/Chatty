#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool a[53]={};
int n,cnt;
string b;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=1;i<=52;i++)
	{
		a[i]=1;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int j=0;
		cin>>b;
		if(b[1]=='A')
		{
			j+=1;
		}
		else if(b[1]=='T')
		{
			j+=10;
		}
		else if(b[1]=='J')
		{
			j+=11;
		}
		else if(b[1]=='Q')
		{
			j+=12;
		}
		else if(b[1]=='K')
		{
			j+=13;
		}
		else
		{
			j+=b[1]-'0';
		}
		
		if(b[0]=='C')
		{
			j+=13;
		}
		else if(b[0]=='H')
		{
			j+=26;
		}
		else if(b[0]=='S')
		{
			j+=39;
		}
		
		a[j]=0;
	}
	for(int i=1;i<=52;i++)
	{
		if(a[i]) cnt++;
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
