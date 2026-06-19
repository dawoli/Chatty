#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char s[10];
	int cnt[10][15]={0},ans=0;
	int m[100]={0};
	m['D']=1,m['C']=2,m['H']=3,m['S']=4;
	int n[100]={0};
	n['A']=1;
	for(int i=2;i<10;i++)
		n[i+48]=i;
	n['T']=10;
	n['J']=11;
	n['Q']=12;
	n['K']=13;
	int a;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>s;
		cnt[m[s[0]]][n[s[1]]]++;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!cnt[i][j])
				ans++;
	cout<<ans;
	return 0;
}
