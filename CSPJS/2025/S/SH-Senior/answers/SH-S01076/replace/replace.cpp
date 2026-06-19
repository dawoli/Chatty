#include <bits/stdc++.h>
using namespace std;
struct node
{
	string s1,s2;
} ss[200005];
string temp[1005][1005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>ss[i].s1>>ss[i].s2;
	}
	for (int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for (int j=1;j<=n;j++)
		{
			for (int k=0;k<t1.size()-ss[j].s1.size()+1;k++)
			{
				//cout<<t1.substr(k,ss[j].s1.size())<<endl;
				if (t1.substr(k,ss[j].s1.size())==ss[j].s1)
				{
					//cout<<t1.substr(0,k)+ss[j].s2+t1.substr(k+ss[j].s1.size())<<endl;
					if (t1.substr(0,k)+ss[j].s2+t1.substr(k+ss[j].s1.size())==t2)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

