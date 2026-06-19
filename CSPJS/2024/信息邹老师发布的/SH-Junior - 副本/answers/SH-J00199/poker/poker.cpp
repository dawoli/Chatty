#include <bits/stdc++.h>
using namespace std;
int n,ans;
char c1,c2;
bool f[52],flag;
int get_id(char ch1,char ch2)
{
	int id=0;
	if (ch1=='C') id = 13;
	else if (ch1=='H') id = 26;
	else if (ch1=='S') id = 39;
	if (ch2=='T') id += 9;
	else if (ch2=='J') id += 10;
	else if (ch2=='Q') id += 11;
	else if (ch2=='K') id += 12;
	else if (ch2!='A') id += ch2-'1';
	return id;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	getchar();
	for (int i=1;i<=n;++i)
	{
		c1 = getchar();
		c2 = getchar();
		getchar();
		int id=get_id(c1,c2);
		f[id] = 1;
	}
	for (int id=0;id<52;++id)
		if (!f[id]) ++ans;
	printf("%d\n",ans);
	return 0;
}
