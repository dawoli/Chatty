#include<bits\stdc++.h>
using namespace std;
int n,q;
string t1,t2;
vector<pair<string, string>> h;
string change(string s,int j)
{
	string a=t1.substr(0,j);
	string c=t1.substr(j+s.length());
	return a+s+c;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q<=1000 && n<=1000)
	{
		for(int i=1;i<=n;++i)
		{
			string s1,s2;
			cin>>s1>>s2;
			h.push_back({s1,s2});
		}
		while(q--)
		{
			cin>>t1>>t2;
			int ans=0;
			for(int i=0;i<h.size();++i)
			{
				string s1,s2;
				s1=h[i].first,s2=h[i].second;
				int len=t1.length()-s1.length();
				for(int j=0;j<=len;++j)
					if(t1.substr(j,s1.length())==s1 && change(s2,j)==t2)
						ans++;
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		while(q--) cout<<0<<'\n';
	}
	return 0;
}
