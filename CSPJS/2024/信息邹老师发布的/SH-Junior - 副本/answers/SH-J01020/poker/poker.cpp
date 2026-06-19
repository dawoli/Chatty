#include<bits/stdc++.h>
using namespace std;
bool a[15][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int n1,n2;
		char c1,c2;
		cin >> c1 >> c2;
		if(c2<='9'&&c2>='2')
			n2=c2-'0';
		else if(c2=='T')
			n2=10;
		else if(c2=='J')
			n2=11;
		else if(c2=='Q')
			n2=12;
		else if(c2=='K')
			n2=13;
		else if(c2=='A')
		    n2=1;
		if(c1=='D')
		    n1=4;
		else if(c1=='C')
		    n1=1;
		else if(c1=='H')
		    n1=3;
		else if(c1=='S')
		    n1=2;
		a[n1][n2]=1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]==0) cnt++;
	    }
    }
	cout << cnt;
	return 0;
}
