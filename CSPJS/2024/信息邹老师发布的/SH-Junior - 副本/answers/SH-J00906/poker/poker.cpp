#include <bits/stdc++.h>
using namespace std;
bool a[53];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,b=52;
	cin>>n;
	for(int i=1;i<=n&&b>0;i++)
	{
		string s;
		cin>>s;
		char c=s[0];
		int t;
		if(c=='D')
			t=0;
		else if(c=='C')
			t=13;
		else if(c=='H')
			t=26;
		else if(c=='S')
			t=39;
		char h=s[1];
		if(h=='A')
			t+=1;
		else if(h=='T')
			t+=10;
		else if(h=='J')	
			t+=11;
		else if(h=='Q')
			t+=12;
		else if(h=='K')
			t+=13;
		else if(h>='2'&&h<='9')
		{
			int k=h-'0';
			t+=k;
		}
		if(a[t]!=1)
		{
			b--;
			a[t]=1;
		}
	}
	cout<<b;
	return 0;
} 
