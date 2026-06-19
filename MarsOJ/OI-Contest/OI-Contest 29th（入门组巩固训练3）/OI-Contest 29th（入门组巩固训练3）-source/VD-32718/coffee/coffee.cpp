#include <bits/stdc++.h>
using namespace std;
int T,n,m,sum;
string s[5][8];
void count(int m)
{
	int sum=0;
	if(m<=5)
	{
		for(int i=0;i<m;i++)
		{
			m++;
			for(int j=0,k=0;i<5,k<8;i++,j++) if(s[i][j]="math") sum++
		}
	}
	else
	{
		days-=(7+1-m);
		m=1;
	}
}
int main()
{
	freopen("coffee.in","r",stdin);
	freopeen("coffee.out","w",stdout);
	cin >> T;
	for(int i=0;i<T;i++)
	{
		for(int j=0,k=0;i<5,k<8;i++,j++) cin >> s[i][j];
		cin >> n >> m;
		sum=count(m);
		cout << sum;
	}
	return 0;
}
