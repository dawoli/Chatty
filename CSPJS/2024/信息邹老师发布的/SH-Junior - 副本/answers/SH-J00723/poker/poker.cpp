#include <bits/stdc++.h>
using namespace std;
char h[150];
int n,m=0;
bool p=1;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char a,b;
		cin>>a>>b;
		h[i*2-1]=a;
		h[i*2]=b;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(h[i*2-1]==h[j*2-1]&&h[i*2]==h[j*2])
			{
				p=0;
				break;
			}
		}
	}
	if(p==1)
	{
		cout<<52-n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(h[i*2-1]==h[j*2-1]&&h[i*2]==h[j*2]&&h[i*2-1]!='X'&&h[j*2-1]!='X'&&h[i*2]!='X'&&h[j*2]!='X')
			{
				m+=2;
				h[i*2-1]='X';
				h[j*2-1]='X';
				h[i*2]='X';
				h[j*2]='X';
			}
		}
	}
	cout<<52-n+m-1;
	return 0;
}
