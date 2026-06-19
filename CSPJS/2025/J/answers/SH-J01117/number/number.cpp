#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::sort;

bool jzhcomp(int a,int b)
{
	return a>b;
}

string jzhs;
int jzhnumbers[1000010],jzhxb;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>jzhs;
	for(unsigned int i=0;i<jzhs.size();i++)
	{
		if(jzhs[i]>='0' && jzhs[i]<='9')
		{
			jzhxb++;
			jzhnumbers[jzhxb]=jzhs[i]-'0';
		}
	}
	sort(jzhnumbers+1,jzhnumbers+1+jzhxb,jzhcomp);
	if(jzhnumbers[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=jzhxb;i++) cout<<jzhnumbers[i];
	return 0;
}
