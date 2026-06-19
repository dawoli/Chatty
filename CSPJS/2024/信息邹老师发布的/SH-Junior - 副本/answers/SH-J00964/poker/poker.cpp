#include <bits/stdc++.h>
using namespace std;
int n,nn=0;
char h[60],d[60];
bool f(char a,char b,int c)
{
	for(int i=1;i<=c;i++)
	{
		if(h[i]==a && d[i]==b)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int i=1;
	cin>>n;
	for(int ii=1;ii<=n;ii++)
	{
		char a,b;
		cin>>a>>b;
		if(f(a,b,i))
		{
			
			continue;
		}
		h[i]=a;d[i]=b;
		nn=i;
		i++;
	}
	if(nn>52)nn=52;
	cout<<(52-nn);
	return 0;
 } 
