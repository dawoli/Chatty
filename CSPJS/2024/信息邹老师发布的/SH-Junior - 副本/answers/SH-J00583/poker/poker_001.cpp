#include<bits/stdc++.h>
using namespace std;
int n,a[14],b[14],c[14],d[14],sum;
void f(char x,char tmp)
{
	if(x=='D')
	{
		if(tmp<='9'&&tmp>='2')a[tmp-48]=1;
		else if(tmp=='T')a[10]=1;
		else if(tmp=='J')a[11]=1;
		else if(tmp=='Q')a[12]=1;
		else if(tmp=='K')a[13]=1;
		else if(tmp=='A')a[1]=1;
	}
	if(x=='C')
	{
		if(tmp<='9'&&tmp>='2')b[tmp-48]=1;
		else if(tmp=='T')b[10]=1;
		else if(tmp=='J')b[11]=1;
		else if(tmp=='Q')b[12]=1;
		else if(tmp=='K')b[13]=1;
		else if(tmp=='A')b[1]=1;
	}
	if(x=='H')
	{
		if(tmp<='9'&&tmp>='2')c[tmp-48]=1;
		else if(tmp=='T')c[10]=1;
		else if(tmp=='J')c[11]=1;
		else if(tmp=='Q')c[12]=1;
		else if(tmp=='K')c[13]=1;
		else if(tmp=='A')c[1]=1;
	}
	if(x=='S')
	{
		if(tmp<='9'&&tmp>='2')d[tmp-48]=1;
		else if(tmp=='T')d[10]=1;
		else if(tmp=='J')d[11]=1;
		else if(tmp=='Q')d[12]=1;
		else if(tmp=='K')d[13]=1;
		else if(tmp=='A')d[1]=1;
	}
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x,tmp;
		cin>>x>>tmp;
		f(x,tmp);
	}
	for(int i=1;i<=13;i++)
	{
		if(a[i]==1)sum++;
		if(b[i]==1)sum++;
		if(c[i]==1)sum++;
		if(d[i]==1)sum++;
	}
	cout<<52-sum;
	return 0;
} 
