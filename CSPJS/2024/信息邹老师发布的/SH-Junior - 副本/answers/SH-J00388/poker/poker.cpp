#include<bits/stdc++.h>
using namespace std;
int s[7][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,tmp,sum=0;
	string a;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a;
		char tmp2=a[1];
		if (!isdigit(tmp2))
		{
			if (tmp2=='A')
			    tmp=1;
			else if (tmp2=='T')
			    tmp=10;
			else if (tmp2=='J')
			    tmp=11;
			else if (tmp2=='Q')
			    tmp=12;
			else
			    tmp=13;
		}
		else
		    tmp=tmp2-'0';
		if (a[0]=='D')
			s[1][tmp]++;
		else if (a[0]=='C')
			s[2][tmp]++;
		else if (a[0]=='H')
		    s[3][tmp]++;
		else
		    s[4][tmp]++;
	}
	for (int i=1;i<=4;i++)
		for (int j=1;j<=13;j++)
			if (!s[i][j])
			    sum++;
    cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

