#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
char c[200001];
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin >> a >> b;
		if(a.size()==b.size())
		{
			mp.insert(make_pair(a,b));
			c[++cnt]=a[0];
		}
	}
	for(int i=1;i<=q;i++)
	{
		string a,b;
		cin >> a >> b;
		int ans=0;
		for(int j=0;j<a.size();j++)
		{
			for(int k=j;k<a.size();k++)
			{
				string ss="";
				for(int m=j;m<=k;m++)
				{
					ss+=a[m];
				}
				string l=mp.find(ss)->second;
				bool f=1;
				for(int m=j;m<=k;m++)
				{
					if(l[j-m]!=b[m]) f=0;
				}
				for(int m=0;m<k;m++)
				{
					if(a[m]!=b[m]) f=0;
				}
				for(int m=k+1;m<a.size();m++)
				{
					if(a[m]!=b[m]) f=0;
				}
				if(f) ans++;
			}
		}
		cout << ans << endl;
	}
} 
