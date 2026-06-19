#include<bits/stdc++.h>
using namespace std;
string str,s[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n;i++)	
	{
		cin>>str;
		bool flag=true;
		for(int i=1;i<=num;i++)
		{
			if(str==s[i]) flag=false;
		}
		if(flag) 
		{
			num++;
			s[num]=str;
		}
	}
	cout<<52-num<<"\n";
	return 0;
}

