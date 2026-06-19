#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::sort;

pair<int,int> jzhlist[1000010];
long long jzha[500010],jzhk,jzhn,jzhlistp,jzhnowst=-1,jzhnowed=-1,jzhans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>jzhn>>jzhk;
	for(int i=1;i<=jzhn;i++)
	{
		cin>>jzha[i];
		if(jzha[i]==jzhk)
		{
			jzhlistp++;
			jzhlist[jzhlistp]=make_pair(i,i);
		}
	}
	for(int i=1;i<=jzhn&&jzhlistp<=1000010;i++)
	{
		int now=jzha[i];
		for(int j=i+1;j<=jzhn&&jzhlistp<=1000010;j++)
		{
			now=now^jzha[j];
			if(now==jzhk)
			{
				jzhlistp++;
				jzhlist[jzhlistp]=make_pair(i,j);
				break;
			}
		}
	}
	sort(jzhlist+1,jzhlist+1+jzhlistp);
	for(int i=1;i<=jzhlistp;i++)
	{
		if(jzhlist[i].first>jzhnowed)
		{
			jzhnowst=jzhlist[i].first;
			jzhnowed=jzhlist[i].second;
			jzhans++;
		}
		else
		{
			if(jzhlist[i].second<jzhnowed)
			{
				jzhnowst=jzhlist[i].first;
				jzhnowed=jzhlist[i].second;
			}
		}
	}
	cout<<jzhans;
	return 0;
}
