#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n= 0;
int T[MAXN];
void input()
{
    for(int i=1;i<=n;i++) cin>>T[i];
}
void solveBF()
{
	for(int i=1;i<=n;i++)
	{
		if(T[i]<=7)
		{
			if(T[i]==2) cout<<1<<endl;
		    if(T[i]==3) cout<<7<<endl;
		    else if(T[i]==4) cout<<4<<endl;
			else if(T[i]==5) cout<<2<<endl;
			else if(T[i]==6) cout<<6<<endl;
			else if(T[i]==7) cout<<8<<endl;
			else cout<<-1;
		}
		else
		{
			for
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%i",&n);
	if(n<=50)
	{
		input();
		solveBF();
	}
	//else if()
	return 0;
}
