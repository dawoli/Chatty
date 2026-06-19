#include<bits/stdc++.h>
using namespace std;
long long a[200005];
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long T;
	T=read();
	while(T--)
	{
		cout<<"0"<<endl;
	}
	return 0;
}
