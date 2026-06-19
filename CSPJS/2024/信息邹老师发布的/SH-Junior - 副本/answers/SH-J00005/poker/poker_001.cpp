#include <bits/stdc++.h>
using namespace std;
int n;
bool ihad[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char k,l;
		cin>>k>>l;
		int num=0;
		if(k=='C')
			num+=13;
		else if(k=='H')
			num+=26;
		else if(k=='S')
			num+=39;
		else if(k!='D')
			num-=100;
		if(l=='A')
			num+=1;
		else if('2'<=l&&l<='9')
			num+=(int)(l-'0');
		else if(l=='T')
			num+=10;
		else if(l=='J')
			num+=11;
		else if(l=='Q')
			num+=12;
		else if(l=='K')
			num+=13;
		if(num>0)
			ihad[num]=true;
	}
	int ans=0;
	for(int i=1;i<=52;i++)
	{
		if(!ihad[i])
			ans++;
	}
	cout<<ans;
}
