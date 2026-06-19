#include<iostream>
using namespace std;
bool temp[5][14];
int list[256];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	list[int('S')]=1;
	list[int('D')]=2;
	list[int('H')]=3;
	list[int('C')]=4;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		char A,B;
		cin>>A>>B;
		a=list[int(A)];
		if(B=='A')	b=1;
		else if(B=='T')	b=10;
		else if(B=='J')	b=11;
		else if(B=='Q')	b=12;
		else if(B=='K')	b=13;
		else b=B-'0';
		temp[a][b]=1;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(!temp[i][j])
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
