#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	map<int,bool>pD;
	map<int,bool>pC;
	map<int,bool>pH;
	map<int,bool>pS;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		string in;
		cin>>in;
		int cnt;
		if(in[1]!='A' && in[1]!='T' && in[1]!='J' && in[1]!='Q' && in[1]!='K'){cnt=in[1]-'0';}
		else if(in[1]=='A')cnt=1;
		else if(in[1]=='T')cnt=10;
		else if(in[1]=='J')cnt=11;
		else if(in[1]=='Q')cnt=12;
		else if(in[1]=='K')cnt=13;
		if(in[0]=='D')pD[cnt]=1;
		if(in[0]=='C')pC[cnt]=1;
		if(in[0]=='H')pH[cnt]=1;
		if(in[0]=='S')pS[cnt]=1;
	}
	int need=0;
	for(int i=1;i<=13;i++)
	{
		if(!pD[i])need++;
		if(!pC[i])need++;
		if(!pH[i])need++;
		if(!pS[i])need++;
	}
	cout<<need;
	return 0;
}

