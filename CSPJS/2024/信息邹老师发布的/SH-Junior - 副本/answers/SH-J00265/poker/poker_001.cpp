#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[10][15];
char b,c;

int x(char q)
{
	if(q=='1') return 1;
	else if(q=='2') return 2;
	else if(q=='3') return 3;
	else if(q=='4') return 4;
	else if(q=='5') return 5;
	else if(q=='6') return 6;
	else if(q=='7') return 7;
	else if(q=='8') return 8;
	else if(q=='9') return 9;
	else if(q=='A') return 1;
	else if(q=='T') return 10;
	else if(q=='J') return 11;
	else if(q=='Q') return 12;
	else if(q=='K') return 13;
	else if(q=='D') return 4;
	else if(q=='C') return 1;
	else if(q=='H') return 3;
	else if(q=='S') return 2;
}

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b>>c;
		a[x(b)][x(c)]+=1;
	}
	for(int i=1;i<=4;i++)
	{
		for(int k=1;k<=13;k++)
		{
			if(a[i][k]==0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
