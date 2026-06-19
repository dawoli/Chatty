#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
int isp(string ss1,string ss2)
{
	if(ss1==ss2)return 1;
	else return ss1==ss2;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		cout<<isp(s1,s2)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
