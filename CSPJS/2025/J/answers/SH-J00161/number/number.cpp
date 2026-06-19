#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string Str;
	cin>>Str;
	int Nm=0;
	int Xx=0;
	while(isalpha(Str[Nm]) ||isdigit(Str[Nm]))
	{
		Xx++;
		Nm++;	
	}
	int Abc[Xx]={0};
	int Bb=0;
	for(int Ii=0;Ii<Xx;Ii++)
	{
		if(Str[Ii]>=48 && Str[Ii]<=57)
		{
			Abc[Bb]=Str[Ii]-48;
			Bb++;
		}
	}
	for(int Ll=0;Ll<Bb;Ll++)
	{
		for(int Ii=1;Ii<Bb;Ii++)
		{
			if(Abc[Ii-1]<Abc[Ii])
			{
				swap(Abc[Ii-1],Abc[Ii]);
			}
		}
	}
	
	for(int Ii=0;Ii<Bb;Ii++)
	{
		cout<<Abc[Ii];
	}
	return 0;
} 
