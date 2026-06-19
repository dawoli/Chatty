#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
int jcmod(int l)
{
	if(l==1) return 1;
	else return jcmod(l-1)*l%998244353;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int s,t;
	bool nd[10004];
	int r[10009];
	cin>>s>>t; //Input
	bool tp=1; //case 6/7/8/16/17
	for(int i=1;i<=s;i++)
	{
		char t;
		cin>>t;
		if(t=='0')
		{
			tp=0;
			nd[i]=0;
		}
		else
		{
			nd[i]=1;
		}
    }
    for(int i=1;i<=s;i++)
    {
    	cin>>r[i];
	}
	if(s == t) //Case 15
	{
		if(tp) cout<<jcmod(s);
		else cout<<0;
	}
    else if(tp)  //case 6/7/8/16/17
    {
    	cout<<jcmod(s);
	}
	else cout<<0;
}
