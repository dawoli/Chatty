#include<bits/stdc++.h>
using namespace std;
int n,ans;
string a;
int x[128];
int y[128];
bool b[10][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	x['A']=1;x['2']=2;x['3']=3;x['4']=4;x['5']=5;x['6']=6;x['7']=7;x['8']=8;x['9']=9;x['T']=10;x['J']=11;x['Q']=12;x['K']=13;
	y['D']=1;y['C']=2;y['H']=3;y['S']=4;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		b[y[a[0]]][x[a[1]]]=true;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			ans+=b[i][j];
		}
	}
	cout<<52-ans<<endl;
	return 0;
}
