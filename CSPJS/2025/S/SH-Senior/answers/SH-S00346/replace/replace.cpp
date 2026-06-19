#include <bits/stdc++.h>
using namespace std;

int n,q;
const int N=2e5+7;
string s1[N],s2[N];
string t1,t2;
vector<int> nxt[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int id=1;id<=n;id++)
	{
		cin>>s1[id]>>s2[id];
		int j=0;
		nxt[id].resize(s1[id].length(),0);
		for(int i=1;i<s1[id].length();i++)
		{
			while(j>0&&s1[id][i]!=s1[id][j]) j=nxt[id][j-1];
			if(s1[id][i]==s1[id][j]) ++j;
			nxt[id][i]=j;
//			cout<<nxt[id][i]<<" ";
		}
//		cout<<endl;
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		for(int id=1;id<=n;id++)
		{
//			cout<<"id="<<id<<endl;
			int j=0;
			for(int i=0;i<t1.length();i++)
			{
				while(j>0&&t1[i]!=s1[id][j]) j=nxt[id][j-1];
				if(t1[i]==s1[id][j]) ++j;
				if(j==s1[id].length())
				{
//					cout<<(i+1)-j+1<<"\n";
					string str=t1;
//					if(i-j+1<0) cout<<"warning";
//					if(i-j+1+s2[id].length()>str.length()) cout<<"warning!"<<endl;
					str.replace(i-j+1,s2[id].length(),s2[id]);
//					cout<<str<<endl;
					if(str==t2) ++ans;
					j=nxt[id][j-1];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/ 
