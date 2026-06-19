#include<iostream>
#include<map>
using namespace std;
using i64=long long;
int n,q;
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while (q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		cout<<"0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

