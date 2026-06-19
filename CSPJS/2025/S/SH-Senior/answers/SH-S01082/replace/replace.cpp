#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
const int Q=2e5+9;

int n,q;
string s[N][2];
string t[Q][2];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>t[i][0]>>t[i][1];
		for(int k=1;k<=n;k++)
		{
			if(t[i][0].find(s[k][0])==-1) continue;
			for(int j=0;j+s[k][0].size()<=t[i][0].size();j++)
			{
				string tmp=t[i][0];
				string sub=tmp.substr(j,s[k][0].size());
				if(sub==s[k][0])
				{
					tmp.replace(j,s[k][0].size(),s[k][1]);
					if(tmp==t[i][1])
					{
						ans++;
						//cout<<"*********"<<tmp<<" "<<t[i][1]<<endl;
					}
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
