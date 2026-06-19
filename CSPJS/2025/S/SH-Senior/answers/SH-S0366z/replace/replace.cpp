#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=2e5+5;
string s[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			int pos=t1.find(s[i][0]);
			while(pos!=-1)
			{
				string t=t1;
				for(int j=pos;j<=pos+s[i][0].size()-1;j++)
				{
					t[j]=s[i][1][j-pos];
				}
				//cout<<t<<endl;
				if(t==t2) ans++;
				pos=t1.find(s[i][0],pos+1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

