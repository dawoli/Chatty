#include<bits/stdc++.h>
using namespace std;
char a[53][3];
bool b[53];
int n,s;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=1;i<=52;i++)
	{
		b[i]=true;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
		bool bj=true;
		for(int j=i-1;j>=1;j--)
		{
			if(a[j][1]==a[i][1]&&a[j][2]==a[i][2])
			{
				bj=false;
			}
		}
		if(bj==true)
			s++;
	}
	cout<<52-s;
	return 0; 
}
