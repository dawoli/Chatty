#include<bits/stdc++.h>
using namespace std;
bool d[14]={},c[14]={},h[14]={},s[14]={};
int n,has=0;
string card;
int findplace(char a)
{
	if(a=='A')    return 1;
	if(a>='2'&&a<='9')      return a-'0';
	if(a=='T')    return 10;
	if(a=='J')    return 11;
	if(a=='Q')    return 12;
	if(a=='K')    return 13;
	return -1;
}                   
void Domain()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>card;
		if(card[0]=='D')
		{
			if(d[findplace(card[1])]==false)
			{
				d[findplace(card[1])]=true;
				has++;
			}
		}
		if(card[0]=='C')
		{
			if(c[findplace(card[1])]==false)
			{
				c[findplace(card[1])]=true;
				has++;
			}
		}
		if(card[0]=='H')
		{
			if(h[findplace(card[1])]==false)
			{
				h[findplace(card[1])]=true;
				has++;
			}
		}
		if(card[0]=='S')
		{
			if(s[findplace(card[1])]==false)
			{
				s[findplace(card[1])]=true;
				has++;
			}
		}
	}
	cout<<52-has;
	fclose(stdin);
	fclose(stdout);
	return;
}
int main()
{
	Domain();
	return 0;
}
