#include <iostream>
#include <cstdio>
using namespace std;
bool s[15],h[15],c[15],f[15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char op,num;
		cin>>op>>num;
		if(op=='S')
		{
			if('2'<=num&&num<='9')
			{
				s[int(num)-'0']=1;
			}
			else if(num=='A')s[1]=1;
			else if(num=='T')s[10]=1;
			else if(num=='J')s[11]=1;
			else if(num=='Q')s[12]=1;
			else if(num=='K')s[13]=1;
		}
		else if(op=='H')
		{
			if('2'<=num&&num<='9')
			{
				h[int(num)-'0']=1;
			}
			else if(num=='A')h[1]=1;
			else if(num=='T')h[10]=1;
			else if(num=='J')h[11]=1;
			else if(num=='Q')h[12]=1;
			else if(num=='K')h[13]=1;
		}
		else if(op=='C')
		{
			if('2'<=num&&num<='9')
			{
				c[int(num)-'0']=1;
			}
			else if(num=='A')c[1]=1;
			else if(num=='T')c[10]=1;
			else if(num=='J')c[11]=1;
			else if(num=='Q')c[12]=1;
			else if(num=='K')c[13]=1;
		}
		else
		{
			if('2'<=num&&num<='9')
			{
				f[int(num)-'0']=1;
			}
			else if(num=='A')f[1]=1;
			else if(num=='T')f[10]=1;
			else if(num=='J')f[11]=1;
			else if(num=='Q')f[12]=1;
			else if(num=='K')f[13]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=13;i++)
	{
		if(s[i]==0)cnt++;
		if(f[i]==0)cnt++;
		if(c[i]==0)cnt++;
		if(h[i]==0)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
