#include<bits/stdc++.h>
using namespace std;
int n,s;
char a[53][3];
bool m;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		m=true;
		cin>>a[i];
		s++;
		for(int j=1;j<i;j++)
		{
			if(m==true && a[i][1]==a[j][1] && a[i][0]==a[j][0])
			{
				s--;
				m=false;	
			}
		}
	}
	cout<<52-s;
	return 0;
} 
