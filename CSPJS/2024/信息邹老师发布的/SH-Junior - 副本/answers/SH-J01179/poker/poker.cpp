#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[5][14], count=52, n;//1·½Æ¬£¬ 2²Ý»¨£¬3ºìÌÒ£¬ 4ºÚÌÒ 
void nm(char c, char b)
{
	int q, o;
	q=int(c);o=int(b)-48;
	if(q==68)q=1;
	else if(q==67)q=2;
	else if(q==72)q=3;
	else q=4; 
	if(o==17)o=1;
	else if(o==36)o=10;
	else if(o==26)o=11;
	else if(o==33)o=12;
	else if(o==27)o=13;
	if(a[q][o]!=1)
	{
		a[q][o]=1;
		count--;
	}
	return;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c, b;
		cin>>c>>b;
		nm(c, b);
	}
	cout<<count<<endl;
	return 0;
}
