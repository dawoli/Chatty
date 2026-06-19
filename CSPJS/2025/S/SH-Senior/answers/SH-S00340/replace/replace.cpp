#include<bits/stdc++.h>
using namespace std;

vector<pair<string, string> > sm;
int n,q;
string s,t;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t;
		sm.push_back({s,t});
	}
	while(q--)
	{
		cin>>s>>t;
		
		if(s.size()!=t.size())
		{
			cout<<0<<endl;
			continue;
		}
		
		int ans=0;
		for(auto p : sm)
		{
//			cout<<p.first<<' '<<p.second<<endl;
			string b=p.first;
			if(b.size()>s.size()) continue;
			
			bool flag=1;
			for(int i=0;i+b.size() <= s.size();i++)
			{
				flag=1;
				for(int j=i;j < i+b.size() ; j ++)
				{
//					cout<<s[j]<<' '<<b[j-i]<<endl;
					if(s[j]!=b[j-i])
					{
						flag=0;
						break;
					}
					
				}
				
//				cout<<"!"<<endl;
				if(!flag) continue;
				
				b=p.second;
				for(int j=0;j < i ; j ++)
				{
					if(t[j]!=s[j])
					{
						flag=0;
						break;
					}
//					cout<<t[j]<<' '<<s[j]<<endl;
				}
//				cout<<"@"<<endl;
				for(int j=i;j < i+b.size() ; j ++)
				{
					if(t[j]!=b[j-i])
					{
						flag=0;
						break;
					}
				}
//				cout<<"?\n";
				for(int j=i+b.size();j < t.size() ; j ++)
				{
					if(t[j]!=s[j])
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
//					cout<<p.first<<' '<<i<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
