#include<bits/stdc++.h>
using namespace std;
int a[1000090];
string b;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	char g;
	bool r=false;
	while(cin>>g)
	{
		if(g>='1'&&g<='9')
		{
			a[int(g)-48]++;
			r=true;
		}
		else if(g=='0')
		{
			a[0]++;
		}
	}
	
	if(r==false)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=a[i];j>0;j--)
		{
			cout<<i;
		}
		
	}
	return 0;
} //#Shang4Shan3Ruo6Shui4
