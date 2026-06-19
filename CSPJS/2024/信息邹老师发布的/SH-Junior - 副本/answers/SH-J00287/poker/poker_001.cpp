#include <bits/stdc++.h>
using namespace std;
long long a[7][20];
char s;
long long n;
long long ans;
int main ( ){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x,y;
		cin>>s;
		if(s=='D')    
			x=1;
		else if(s=='C')
			x=2;
		else if(s=='H')
			x=3;
		else
			x=4;
		cin>>s;
		if('2'<=s&&s<='9') 
			y=s-'0';
		else if(s=='A')
			y=1;
		else if(s=='T')
			y=10;
		else if(s=='J')
			y=11;
		else if(s=='Q')
			y=12;
		else
			y=13;
		if(a[x][y]==0)  
		{
			ans++;
			a[x][y]=1;
		} 
	}
	cout<<52-ans;
	return 0; 
}
